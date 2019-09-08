#!/usr/bin/awk -f

# $NetBSD: larger_symbol_version.awk,v 1.1 2019/09/08 14:47:53 maya Exp $

# Copyright (c) 2019 Maya Rashish <maya@NetBSD.org>.
# All rights reserved.
#
# This code is derived from software contributed to The NetBSD Foundation
# by Maya Rashish.
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

# For each absolute symbol in an ELF binary, extract the component
# of the symbol name that looks like a version.
#
# If the supplied version is larger, return 1
# 
# example:
#     echo "/usr/lib/libgcc_s.so 3.4" | awk -f larger_symbol_version.awk

BEGIN {
	nm = ENVIRON["NM"]
	if (nm == "")
		nm = "nm"
}


function largest_symbol_version(ELF) {
	cmd = nm " -D " ELF " 2>/dev/null"
	while ((cmd | getline) > 0) {
		# Absolute symbol of the form ALPHABET_3.4
		if (($2 == "A") && ($3 ~ /[A-Za-z_]*[0-9]*\.[0-9]*/)) {
			split($3, matches, ".")

			sub(/[A-Za-z_]*/,"",matches[1])

			current_major = int(matches[1])
			current_minor = int(matches[2])

			if ((current_major > target_major) ||
			   ((current_major == target_major) &&
			    (current_minor > target_minor))) {
				print "the version of " ELF " is newer than target version " target_major "." target_minor
				exit 0
			}
		}
	}
	print "the version of " ELF " is older or equal to target version " target_major "." target_minor
	exit 0
}

{ 

	split($NF, target_version, ".")
	target_major = target_version[1]
	target_minor = target_version[2]

	largest_symbol_version($1);
}
