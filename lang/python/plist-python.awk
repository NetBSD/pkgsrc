# $NetBSD: plist-python.awk,v 1.4 2023/10/26 10:10:23 wiz Exp $
#
# Copyright (c) 2012 The NetBSD Foundation, Inc.
# All rights reserved.
#
# This code is derived from software contributed to The NetBSD Foundation
# by OBATA Akio.
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

### This awk script handles Python bytecode file entries in PLISTs.  This script
### requires the following scripts to be included:
###
###	plist-functions.awk (print_entry)
###
### Certain environment variables must be set prior to running this script:
###
###	PYVERS
###
BEGIN {
	PYVERS = getenv_or_die("PYVERS")
}

### For each Python bytecode file entry, convert directory and file name.
###
/^[^@]/ && /[^\/]+\.py[co]$/ {
	sub(/[^\/]+\.py[co]$/, "__pycache__/&")
	sub(/\.py[co]$/, ".cpython-" PYVERS "&")
	if (PYVERS ~ /^3[0-9]+$/ && $0 ~ /\.pyo$/) {
		sub(/\.pyo$/, ".opt-1.pyc")
	}
}
