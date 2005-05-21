# $NetBSD: perl.mk,v 1.15 2005/05/21 04:46:52 jlam Exp $
#
# Copyright (c) 2005 The NetBSD Foundation, Inc.
# All rights reserved.
#
# This code is derived from software contributed to The NetBSD Foundation
# by Johnny C. Lam
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
#

#
# This Makefile fragment defines additional variables that are used by
# packages that use the perl tool.
#

.if defined(_USE_TOOLS) && !empty(_USE_TOOLS:Mperl)
#
# GNU configure scripts need to be told where to the real Perl
# interpreter can be found.  This value is typically hardcoded into
# Perl shebang scripts.
#
CONFIGURE_ENV+=		PERL=${TOOLS_${_TOOLS_VARNAME.perl}:Q}
#
# Define PERL5_* variables that locate the site directories for
# ${PERL5}.  These variables depend on PERL5 being properly defined
# and existing on the filesystem.  This needs to be done _after_
# ${PERL5} is fully resolved, which happens after mk/tools/replace.mk
# includes find-prefix.mk.
#
.  include "../../lang/perl5/vars.mk"

# Substitute for PERL5_* variables in PLISTs.
PLIST_SUBST+=	PERL5_SITELIB=${PERL5_SUB_INSTALLSITELIB}
PLIST_SUBST+=	PERL5_SITEARCH=${PERL5_SUB_INSTALLSITEARCH}
PLIST_SUBST+=	PERL5_ARCHLIB=${PERL5_SUB_INSTALLARCHLIB}
.endif
