# $NetBSD: plist-info.awk,v 1.18 2018/08/22 20:48:37 maya Exp $
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

### This awk script handles *.info file entries in PLISTs.  This script
### requires the following scripts to be included:
###
###	plist-functions.awk (print_entry)
###
### Certain environment variables must be set prior to running this script:
###
### IGNORE_INFO_PATH is a colon-separated list of ${PREFIX}-relative paths
###	that do *not* contain info files.
###
### PKGINFODIR is the ${PREFIX}-relative path to the installed info pages.
###
### LS is the path to the "ls" binary.
###
### MANZ is a yes/no variable that determines whether the info pages
###	should be recorded as compressed or not.
###
### PREFIX is the installation prefix of the the package.
###
### TEST is the command used for shell tests, e.g. shell test built-in or
###	the path to a "test" binary.
###
BEGIN {
	PKGINFODIR = ENVIRON["PKGINFODIR"] ? ENVIRON["PKGINFODIR"] : "info"
	LS = ENVIRON["LS"] ? ENVIRON["LS"] : "ls"
	MANZ = ENVIRON["MANZ"] ? ENVIRON["MANZ"] : "no"
	PREFIX = ENVIRON["PREFIX"] ? ENVIRON["PREFIX"] : "/usr/pkg"
	TEST = ENVIRON["TEST"] ? ENVIRON["TEST"] : "test"

	IGNORE_INFO_REGEXP = ENVIRON["IGNORE_INFO_PATH"] ? ENVIRON["IGNORE_INFO_PATH"] : ""
	if (IGNORE_INFO_REGEXP != "") {
		gsub(":", "|", IGNORE_INFO_REGEXP)
		IGNORE_INFO_REGEXP = "(" IGNORE_INFO_REGEXP ")"
	}
}

###
### Canonicalize info page entries by converting ${PKGINFODIR}/ to info/.
###
/^[^@]/ && ($0 !~ "^" IGNORE_INFO_REGEXP "/") && \
($0 ~ "^" PKGINFODIR "/[^/]+(\\.info)?(-[0-9]+)?(\\.gz)?$") {
	sub("^" PKGINFODIR "/", "info/")
}

###
### Canonicalize info page entries by stripping any ".gz" suffixes.
###
/^[^@]/ && ($0 !~ "^" IGNORE_INFO_REGEXP "/") && \
/^([^\/]*\/)*(info\/[^\/]+(\.info)?|[^\/]+\.info)(-[0-9]+)?\.gz$/ {
	sub("\\.gz$", "")
}

###
### Ignore *-1, *-2, etc. files in the PLIST as we get the list of
### installed split files below.
###
/^[^@]/ && ($0 !~ "^" IGNORE_INFO_REGEXP "/") && \
/^([^\/]*\/)*(info\/[^\/]+(\.info)?|[^\/]+\.info)-[0-9]+$/ {
	next
}

###
### For each info page entry, convert any info/ to ${PKGINFODIR}/ and print
### all of the installed info sub-pages associated with that entry.
###
/^[^@]/ && ($0 !~ "^" IGNORE_INFO_REGEXP "/") && \
/^([^\/]*\/)*(info\/[^\/]+(\.info)?|[^\/]+\.info)$/ {
	sub("^info/", PKGINFODIR "/")
	cmd = TEST " -f " PREFIX "/" $0 " -o -f " PREFIX "/" $0 ".gz"
	if (system(cmd) == 0) {
		len = length
		cmd = "cd " PREFIX " && " LS " -1 " $0 "*"
		while (cmd | getline) {
			# Filter out unrelated info files
			if (substr($0, len + 1) !~ "^(-[0-9]+)?(\\.gz)?$") {
				continue
			}
			#if ((MANZ ~ /[yY][eE][sS]/) && ($0 !~ /\.gz$/)) {
			#	$0 = $0 ".gz"
			#} else if ((MANZ !~ /[yY][eE][sS]/) && ($0 ~ /\.gz$/)) {
			#	sub("\\.gz$", "")
			#}
			print_entry($0)
		}
		close(cmd)
	} else {
		#if ((MANZ ~ /[yY][eE][sS]/) && ($0 !~ /\.gz$/)) {
		#	$0 = $0 ".gz"
		#} else if ((MANZ !~ /[yY][eE][sS]/) && ($0 ~ /\.gz$/)) {
		#	sub("\\.gz$", "")
		#}
		print_entry($0)
	}
	next
}
