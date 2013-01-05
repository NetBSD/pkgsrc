# $NetBSD: plist-gnu.awk,v 1.2 2013/01/05 07:32:50 sbd Exp $
#
# Copyright (c) 2012 The NetBSD Foundation, Inc.
# All rights reserved.
#
# This code is derived from software contributed to The NetBSD Foundation
# by Jonathan Perkin
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

### This awk script handles gnu entries in PLISTs.  This script
### requires the following scripts to be included:
###
###     plist-functions.awk (print_entry)
###
### Certain environment variables must be set prior to running this script:
###
###   PKGGNUDIR is the ${PREFIX}-relative path to the installed GNU files.
###   PKGMANDIR is the ${PKGGNUDIR}-relative path to the install GNU manpages.
###
BEGIN {
	# PKGGNUDIR is allowed to be empty so we do not provide a default.
	PKGGNUDIR = ENVIRON["PKGGNUDIR"]
	PKGMANDIR = ENVIRON["PKGMANDIR"] ? ENVIRON["PKGMANDIR"] : "man"
}

###
### Convert gnu/man to ${PKGGNUDIR}${PKGMANDIR} for all GNU manpages.
###
/^[^@]/ && \
/^gnu\/man\// {
	sub("^gnu/man", PKGGNUDIR PKGMANDIR)
}
###
### Convert gnu/ to ${PKGGNUDIR} for all GNU file entries.
###
/^[^@]/ && \
/^gnu\// {
	sub("^gnu/", PKGGNUDIR)
}
