# $NetBSD: plist-man.awk,v 1.13 2018/08/22 20:48:37 maya Exp $
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

### This awk script handles man page entries in PLISTs.  This script
### requires the following scripts to be included:
###
###     plist-functions.awk (print_entry)
###
### Certain environment variables must be set prior to running this script:
###
### CATMAN_SECTION_SUFFIX is a yes/no variable that determines whether to use
###	the catman page section as the suffix or .0 if not.
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
function getenv(varname, defval) {
	return varname in ENVIRON ? ENVIRON[varname] : defval;
}

BEGIN {
	IMAKE_MANINSTALL = getenv("IMAKE_MANINSTALL", "maninstall catinstall")
	MANINSTALL = getenv("MANINSTALL", "maninstall catinstall")
	MANZ = getenv("MANZ", "no")
	PKGMANDIR = getenv("PKGMANDIR", "man")
	CATMAN_SECTION_SUFFIX = getenv("CATMAN_SECTION_SUFFIX", "no")
	CATPAGE_REGEX = "cat[1-9ln](am|f)?/[^/]*\\.[0-9ln](am|f)?"
	MANPAGE_REGEX = "(man|html)[1-9ln](am|f)?/[^/]*\\.([1-9ln](am|f)?|html)"
	CATORMAN_REGEX = "(" MANPAGE_REGEX "|" CATPAGE_REGEX ")"
}

###
### Canonicalize man page entries by stripping any ".gz" suffixes.
###
/^[^@]/ && $0 ~ "^([^/]*/)+" CATORMAN_REGEX "\\.gz$" {
	sub("\\.gz$", "")
}

###
### Rewrite "imake-installed" catman pages as man pages if imake only
### supports man pages.
###
(IMAKE_MANINSTALL == "maninstall") && /^[^@]/ && $0 ~ "^([^/]*/)+" CATPAGE_REGEX "$" {
	n = split($0, components, "/")
	sub("cat", "man", components[n-1])
	section = substr(components[n-1], 4, 1)
	sub("[0-9ln]$", section, components[n])
	$0 = join(components, 1, n, "/")
}

###
### Rewrite "imake-installed" man pages as catman pages if imake only
### supports catman pages.
###
(IMAKE_MANINSTALL == "catinstall") && /^[^@]/ && $0 ~ "^([^/]*/)+" MANPAGE_REGEX "$" {
	n = split($0, components, "/")
	sub("man", "cat", components[n-1])
	if (CATMAN_SECTION_SUFFIX ~ /[yY][eE][sS]/) {
		section = substr(components[n-1], 4, 1)
	} else {
		section = "0"
	}
	sub("[0-9ln]$", section, components[n])
	$0 = join(components, 1, n, "/")
}

###
### If MANINSTALL doesn't contain "maninstall", then strip out man page
### entries from the PLIST, and similarly for "catinstall" and catman page
### entries.
###
(MANINSTALL !~ /catinstall/) && /^[^@]/ && $0 ~ "^([^/]*/)+" CATPAGE_REGEX "$" {
	next
}
(MANINSTALL !~ /maninstall/) && /^[^@]/ && $0 ~ "^([^/]*/)+" MANPAGE_REGEX "$" {
	next
}

###
### Fixup catman entries to use section suffixes if required.
###
(CATMAN_SECTION_SUFFIX ~ /[yY][eE][sS]/)&& /^[^@]/ && $0 ~ "^man/([^/]*/)?" CATPAGE_REGEX {
	n = split($0, components, "/")
	sub("^cat", "", components[n-1])
	sub("0$", components[n-1], $0)
}

###
### Convert man/ to ${PKGMANDIR}/ for all man and catman page entries.
###
/^[^@]/ && $0 ~ "^man/([^/]*/)?" CATORMAN_REGEX {
	sub("^man/", PKGMANDIR "/")
}

###
### Append ".gz" to the end of man page entries if compressed pages are
### requested.
###
(MANZ ~ /[yY][eE][sS]/) && /^[^@]/ && $0 ~ "^([^/]*/)+" CATORMAN_REGEX "$" {
	$0 = $0 ".gz"
}
