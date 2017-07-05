# $NetBSD: check-relro-elf.awk,v 1.2 2017/07/05 15:24:22 khorben Exp $
#
# Copyright (c) 2007 Joerg Sonnenberger <joerg@NetBSD.org>.
# Copyright (c) 2017 Pierre Pronchery <khorben@NetBSD.org>.
# All rights reserved.
#
# This code is derived from software contributed to The NetBSD Foundation
# by Joerg Sonnenberger.
#
# Originally developed as part of Google's Summer of Code 2007 program.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
#
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in
#    the documentation and/or other materials provided with the
#    distribution.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
# ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
# LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
# FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE
# COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
# INCIDENTAL, SPECIAL, EXEMPLARY OR CONSEQUENTIAL DAMAGES (INCLUDING,
# BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
# LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
# AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
# OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
# OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
# SUCH DAMAGE.

#
# Read a list of potential ELF binaries from stdin.
# For each, extract the list of program headers.
# Check that the GNU_RELRO header is present.
#

function shquote(IN, out) {
	out = IN;
	gsub("\\\\", "\\\\", out);
	gsub("\\\n", "\\n", out);
	gsub("\\\t", "\\t", out);
	gsub(" ", "\\ ", out);
	gsub("'", "\\'", out);
	gsub("`", "\\`", out);
	gsub("\"", "\\\"", out);
	gsub(";", "\\;", out);
	gsub("&", "\\&", out);
	gsub("<", "\\<", out);
	gsub(">", "\\>", out);
	gsub("\\(", "\\(", out);
	gsub("\\)", "\\)", out);
	gsub("\\|", "\\|", out);
	gsub("\\*", "\\*", out);
	gsub("\\?", "\\?", out);
	gsub("\\{", "\\{", out);
	gsub("\\}", "\\}", out);
	gsub("\\[", "\\[", out);
	gsub("\\]", "\\]", out);
	gsub("\\$", "\\$", out);
	gsub("!", "\\!", out);
	gsub("#", "\\#", out);
	gsub("\\^", "\\^", out);
	gsub("~", "\\~", out);
	return out;
}

function checkrelro(ELF, got_relro, found) {
	cmd = readelf " -Wl " shquote(ELF) " 2> /dev/null"
	while ((cmd | getline) > 0) {
		found = 1
		if ($1 == "GNU_RELRO") {
			got_relro = 1
		}
	}
	close(cmd)
	if (found == 1 && got_relro != 1) {
		print ELF ": missing RELRO"
	}
}

BEGIN {
	readelf = ENVIRON["READELF"]
	if (readelf == "")
		readelf = "readelf"
}

{ checkrelro($0); }
