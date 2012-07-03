#!/usr/bin/awk -f
#
# $NetBSD: reduce-resolved-depends.awk,v 1.1.2.2 2012/07/03 23:24:24 tron Exp $
#
# Copyright (c) 2012 The NetBSD Foundation, Inc.
# All rights reserved.
#
# This code is derived from software contributed to The NetBSD Foundation
# by Joerg Sonnenberger.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
#
# THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS
# ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
# TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
# PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS
# BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.
#

######################################################################
#
# NAME
#	reduce-resolved-depends.awk -- drop redundant build dependencies
#
# SYNOPSIS
#	reduce-resolved-depends.awk
#
# DESCRIPTION
#	reduce-resolved-depends.awk removes build dependencies from the
#	dependency list on stdin, if they provided as dependency of
#	one of the full dependencies in the list.
#
# ENVIRONMENT
#	CAT
#	PKG_INFO
#
######################################################################

BEGIN {
	CAT = ENVIRON["CAT"] ? ENVIRON["CAT"] : "cat"
	PKG_INFO = ENVIRON["PKG_INFO"] ? ENVIRON["PKG_INFO"] : "pkg_info"

	PROGNAME = "reduce-resolved-depends.awk"
	ERRCAT = CAT " 1>&2"

	while (getline == 1) {
		if (NF != 3) {
			print "ERROR: [" PROGNAME "] invalid dependency line " $0 | ERRCAT
			exit 1
		}
		if ($1 != "full" && $1 != "build" && $1 != "bootstrap") {
			print "ERROR: [" PROGNAME "] invalid dependency line " $0 | ERRCAT
			exit 1
		}
		type[NR] = $1
		pattern[NR] = $2
		pkg[NR] = $3
	}
	lines = NR + 1

	# Register all full dependencies first.
	# Keep track of the first line for each of them to skip duplicates later.
	for (i = 0; i < lines; ++i) {
		if (type[i] == "full" && checked_full[pkg[i]] != 1) {
			checked_full[pkg[i]] = 1
			checked_build[pkg[i]] = 1
			checked_bootstrap[pkg[i]] = 1
			print_line[i] = 1
		}
	}

	for (i = 0; i < lines; ++i) {
		if (type[i] == "bootstrap" && checked_bootstrap[pkg[i]] != 1) {
			checked_bootstrap[pkg[i]] = 1
			found = 0
			cmd = PKG_INFO " -qr " pkg[i]
			while (cmd | getline dpkg) {
				if (checked_full[dpkg] == 1)
					found = 1
			}
			close(cmd)
			if (found == 0)
				print_line[i] = 1
		}
	}

	for (i = 0; i < lines; ++i) {
		if (type[i] == "build" && checked_build[pkg[i]] != 1) {
			checked_build[pkg[i]] = 1
			if (checked_bootstrap[pkg[i]] == 1)
				continue
			found = 0
			cmd = PKG_INFO " -qr " pkg[i]
			while (cmd | getline dpkg) {
				if (checked_full[dpkg] == 1)
					found = 1
			}
			close(cmd)
			if (found == 0)
				print_line[i] = 1
		}
	}

	for (i = 0; i < lines; ++i) {
		if (print_line[i] == 1)
			printf("%s\t%s\t%s\n", type[i], pattern[i], pkg[i])
	}
}
