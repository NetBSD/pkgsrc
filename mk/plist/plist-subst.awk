# $NetBSD: plist-subst.awk,v 1.4 2018/08/22 20:48:37 maya Exp $
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

###
### Build an array "substitute" of <regexp, value> pairs, that may be used
### to do variable substitutions in PLIST entries.  The variables which
### will be substituted are passed in the environment variable
### PLIST_SUBST_VARS, and the named variables should be found in the
### shell environment.
###
BEGIN {
	PLIST_SUBST_VARS = ENVIRON["PLIST_SUBST_VARS"]

	split(PLIST_SUBST_VARS, vars, " ")
	for (i in vars) {
		value = ENVIRON[vars[i]]
		var = vars[i]
		sub("^PLIST_", "", var)
		regexp = "[$][{]" var "[}]"
		substitute[regexp] = value
	}
}

###
### For each entry, replace all ${...} variables with their respective
### values taken from the environment.
###
{
	for (regexp in substitute) {
		gsub(regexp, substitute[regexp])
	}
}
