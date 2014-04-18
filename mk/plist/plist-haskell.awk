# $NetBSD: plist-haskell.awk,v 1.1 2014/04/18 13:42:59 obache Exp $
#
# Copyright (c) 2014 The NetBSD Foundation, Inc.
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

### This awk script handles haskell related entries in PLISTs.  This script
### requires the following scripts to be included:
###
###     plist-functions.awk (print_entry)
###
### Certain environment variables must be set prior to running this script:
###
###   HASKELL_VERSION_SUFFIX is the haskell shlib version suffix.
###   HASKELL_SHLIB_SUFFIX is the haskell shlib suffix.
###   HASKELL_ENABLE_SHARED_LIBRARY is a yes/no variable indicating whether
###	shared library should be built or not.
###   HASKELL_ENABLE_LIBRARY_PROFILING is a yes/no variable indicating whether
###	profiling library should be built or not.
###
BEGIN {
	HASKELL_VERSION_SUFFIX = ENVIRON["HASKELL_VERSION_SUFFIX"]
	HASKELL_SHLIB_SUFFIX = ENVIRON["HASKELL_SHLIB_SUFFIX"]
	HASKELL_ENABLE_SHARED_LIBRARY = ENVIRON["HASKELL_ENABLE_SHARED_LIBRARY"]
	HASKELL_ENABLE_LIBRARY_PROFILING = ENVIRON["HASKELL_ENABLE_LIBRARY_PROFILING"]
}

###
### Convert .hi
###
/^[^@]/ && \
/^lib\/.*\.hi$/ {
	if (HASKELL_ENABLE_SHARED_LIBRARY ~ /[yY][eE][sS]/) {
		dyn_hi = $0;
		sub(/\.hi$/, ".dyn_hi", dyn_hi);
		print_entry(dyn_hi);
	}
	if (HASKELL_ENABLE_LIBRARY_PROFILING ~ /[yY][eE][sS]/) {
		p_hi = $0;
		sub(/\.hi$/, ".p_hi", p_hi);
		print_entry(p_hi);
	}
}

###
### Convert .a
###
/^[^@]/ && \
/^lib\/.*\/lib[^\/]*\.a$/ {
	if (HASKELL_ENABLE_SHARED_LIBRARY ~ /[yY][eE][sS]/) {
		dyn_ar = $0;
		sub(/\.a$/, "-" HASKELL_VERSION_SUFFIX "." HASKELL_SHLIB_SUFFIX, dyn_ar);
		print_entry(dyn_ar);
	}
	if (HASKELL_ENABLE_LIBRARY_PROFILING ~ /[yY][eE][sS]/) {
		p_ar = $0;
		sub(/\.a$/, "_p.a", p_ar);
		print_entry(p_ar);
	}
}

