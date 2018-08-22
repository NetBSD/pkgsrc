# $NetBSD: plist-libtool.awk,v 1.6 2018/08/22 20:48:37 maya Exp $
#
# Copyright (c) 2006 The NetBSD Foundation, Inc.
# All rights reserved.
#
# This code is derived from software contributed to The NetBSD Foundation
# by Johnny C. Lam.
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

### This awk script handles libtool archive entries in PLISTs.  This script
### requires the following scripts to be included:
###
###	plist-functions.awk (print_entry)
###
### Certain environment variables must be set prior to running this script:
###
### IGNORE_LIBTOOLIZE is a whitespace-separated list of ${PREFIX}-relative
###	paths to *.la files that should not be expanded.
###
### LIBTOOL_EXPAND is the path to the script that prints out the
###	actual library files associated with a libtool archive file.
###
### LIBTOOLIZE_PLIST is a yes/no variable indicating whether to expand
###	*.la files in the PLIST into the corresponding real libraries.
###
### PREFIX is the installation prefix of the package.
###
### TEST is the command used for shell tests, e.g. shell test built-in or
###	the path to a "test" binary.
###

BEGIN {
	LIBTOOL_EXPAND = ENVIRON["LIBTOOL_EXPAND"] ? ENVIRON["LIBTOOL_EXPAND"] : "/usr/pkgsrc/mk/plist/libtool-expand"
	LIBTOOLIZE_PLIST = ENVIRON["LIBTOOLIZE_PLIST"] ? ENVIRON["LIBTOOLIZE_PLIST"] : "yes"
	PREFIX = ENVIRON["PREFIX"] ? ENVIRON["PREFIX"] : "/usr/pkg"
	TEST = ENVIRON["TEST"] ? ENVIRON["TEST"] : "test"

	IGNORE_LA_REGEXP = ENVIRON["IGNORE_LIBTOOLIZE"] ? ENVIRON["IGNORE_LIBTOOLIZE"] : ""
	if (IGNORE_LA_REGEXP != "") {
		gsub("  *", "|", IGNORE_LA_REGEXP)
		IGNORE_LA_REGEXP = "(" IGNORE_LA_REGEXP ")"
	}
}

###
### Expand libtool archives into the list of corresponding shared and/or
### static libraries.
###
(LIBTOOLIZE_PLIST ~ /[yY][eE][sS]/) && \
/^[^@]/ && ($0 !~ "^" IGNORE_LA_REGEXP "$") && /\.la$/ {
	print_entry($0)
	cmd = TEST " -f " PREFIX "/" $0
	if (system(cmd) == 0) {
		cmd = "cd " PREFIX " && " LIBTOOL_EXPAND " " $0
		while (cmd | getline) {
			print_entry($0)
		}
		close(cmd)
	}
	next
}
