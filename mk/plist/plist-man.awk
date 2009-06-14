# $NetBSD: plist-man.awk,v 1.6 2009/06/14 22:58:05 joerg Exp $
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
# 3. All advertising materials mentioning features or use of this software
#    must display the following acknowledgement:
#        This product includes software developed by the NetBSD
#        Foundation, Inc. and its contributors.
# 4. Neither the name of The NetBSD Foundation nor the names of its
#    contributors may be used to endorse or promote products derived
#    from this software without specific prior written permission.
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

### This awk script handles man page entries in PLISTs.  This script
### requires the following scripts to be included:
###
###     plist-functions.awk (print_entry)
###
### Certain environment variables must be set prior to running this script:
###
### IMAKE_MANINSTALL specifies how imake-using packages install man pages.
###	Valid values are:
###
###	    no value	the package doesn't use imake
###	    maninstall	the package installed man pages
###	    catinstall  the package installed catman pages
###
###	Both "maninstall" and "catinstall" may be specified.
###
### MANINSTALL specifies if man pages are installed by the package.
###	Valid values are:
###
###	    maninstall	the package installed man pages
###	    catinstall  the package installed catman pages
###
###	Both "maninstall" and "catinstall" may be specified.
###
### MANZ is a yes/no variable that determines whether the man pages
###     should be recorded as compressed or not.
###
### PKGMANDIR is the ${PREFIX}-relative path to the installed man pages.
###
BEGIN {
	IMAKE_MANINSTALL = ENVIRON["IMAKE_MANINSTALL"] ? ENVIRON["IMAKE_MANINSTALL"] : "maninstall catinstall"
	MANINSTALL = ENVIRON["MANINSTALL"] ? ENVIRON["MANINSTALL"] : "maninstall catinstall"
	MANZ = ENVIRON["MANZ"] ? ENVIRON["MANZ"] : "no"
	PKGMANDIR = ENVIRON["PKGMANDIR"] ? ENVIRON["PKGMANDIR"] : "man"
}

###
### Canonicalize man page entries by stripping any ".gz" suffixes.
###
/^[^@]/ && \
/^([^\/]*\/)+(man[1-9ln]\/[^\/]*\.[1-9ln]|cat[1-9ln]\/[^\/]*\.[0-9])\.gz$/ {
	sub("\\.gz$", "")
}

###
### Rewrite "imake-installed" catman pages as man pages if imake only
### supports man pages.
###
(IMAKE_MANINSTALL == "maninstall") && /^[^@]/ && \
/^([^\/]*\/)+cat[1-9ln]\/[^\/]*\.[0-9ln]$/ {
	n = split($0, components, "/")
	sub("cat", "man", components[n-1])
	section = substr(components[n-1], 4, 1)
	sub("[0-9ln]$", section, components[n])
	$0 = join(components, 1, n, "/")
}
(IMAKE_MANINSTALL == "maninstall") && \
/^@dirrm ([^\/]*\/)+cat[1-9ln]/ {
	next
}

###
### Rewrite "imake-installed" man pages as catman pages if imake only
### supports catman pages.
###
(IMAKE_MANINSTALL == "catinstall") && /^[^@]/ && \
/^([^\/]*\/)+man[1-9ln]\/[^\/]*\.[0-9ln]$/ {
	n = split($0, components, "/")
	sub("man", "cat", components[n-1])
	section = "0"
	sub("[0-9ln]$", section, components[n])
	$0 = join(components, 1, n, "/")
}
(IMAKE_MANINSTALL == "catinstall") && \
/^@dirrm ([^\/]*\/)+man[1-9ln]/ {
	next
}

###
### If MANINSTALL doesn't contain "maninstall", then strip out man page
### entries from the PLIST, and similarly for "catinstall" and catman page
### entries.
###
(MANINSTALL !~ /catinstall/) && /^[^@]/ && \
/^([^\/]*\/)+cat[1-9ln]\/[^\/]*\.[0-9ln]$/ {
	next
}
(MANINSTALL !~ /maninstall/) && /^[^@]/ && \
/^([^\/]*\/)+man[1-9ln]\/[^\/]*\.[0-9ln]$/ {
	next
}

###
### Append ".gz" to the end of man page entries if compressed pages are
### requested.
###
(MANZ ~ /[yY][eE][sS]/) && /^[^@]/ && \
/^([^\/]*\/)+(man[1-9ln]\/[^\/]*\.[1-9ln]|cat[1-9ln]\/[^\/]*\.[0-9])$/ {
	$0 = $0 ".gz"
}

###
### Convert man/ to ${PKGMANDIR}/ for all man and catman page entries.
###
/^[^@]/ && \
/^man\/([^\/]*\/)?(man[1-9ln]\/[^\/]*\.[1-9ln]|cat[1-9ln]\/[^\/]*\.[0-9])/ {
	sub("^man/", PKGMANDIR "/")
}
