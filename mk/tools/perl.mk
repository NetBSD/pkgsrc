# $NetBSD: perl.mk,v 1.25 2018/08/22 20:48:37 maya Exp $
#
# Copyright (c) 2005 The NetBSD Foundation, Inc.
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
#

#
# This Makefile fragment defines additional variables that are used by
# packages that use the perl tool.
#

.if defined(_USE_TOOLS) && !empty(_USE_TOOLS:Mperl)
#
# Define PERL5_* variables that locate the site directories for
# ${PERL5}.  These variables depend on PERL5 being properly defined
# and existing on the filesystem.
#
.  include "../../lang/perl5/vars.mk"
.else
#
# If a package doesn't explicitly say it uses perl, then create a "broken"
# perl in the tools directory.
#
TOOLS_FAIL+=		perl
TOOLS_PATH.perl=	${TOOLS_CMD.perl}
#
# Some packages want the path to the perl tool, even if they don't have
# dependency on perl, e.g. devel/cvs.
#
.  if defined(TOOLS_PLATFORM.perl) && !empty(TOOLS_PLATFORM.perl)
TOOLS_${_TOOLS_VARNAME.perl}?=	${TOOLS_PLATFORM.perl}
.  else
TOOLS_${_TOOLS_VARNAME.perl}?=	${LOCALBASE}/bin/perl
.  endif
.  if !defined(${_TOOLS_VARNAME.perl})
${_TOOLS_VARNAME.perl}?=	${TOOLS_${_TOOLS_VARNAME.perl}}
.  endif
.endif
