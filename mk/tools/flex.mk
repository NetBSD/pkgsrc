# $NetBSD: flex.mk,v 1.3 2018/08/22 20:48:37 maya Exp $
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

FLEX_REQD?=		2.5.4

# If the package does explicitly request flex as a tool, then determine if the
# platform-provided flex's version is at least ${FLEX_REQD}.  If it isn't, then
# tell the tools framework to use the pkgsrc flex.
#

.if !empty(USE_TOOLS:C/:.*//:Mflex) && \
    defined(TOOLS_PLATFORM.flex) && !empty(TOOLS_PLATFORM.flex)
.  if !defined(_TOOLS_USE_PKGSRC.flex)
_TOOLS_VERSION.flex!=							\
	${TOOLS_PLATFORM.flex} --version |				\
	${SED} -e 's/^[[:blank:]]*\([^[:blank:]]\{1,\}\)[[:blank:]]\{1,\}\([^[:blank:]]\{1,\}\).*$$/\2/'
_TOOLS_PKG.flex=		flex-${_TOOLS_VERSION.flex}
_TOOLS_USE_PKGSRC.flex=	no
.    for _dep_ in flex>=${FLEX_REQD}
.      if !empty(_TOOLS_USE_PKGSRC.flex:M[nN][oO])
_TOOLS_USE_PKGSRC.flex!=						\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${_TOOLS_PKG.flex:Q}; then \
		${ECHO} no;						\
	else								\
		${ECHO} yes;						\
	fi
.      endif
.    endfor
.  endif
MAKEVARS+=	_TOOLS_USE_PKGSRC.flex
.endif

CONFIGURE_ENV+=		FLEX=${TOOLS_CMD.flex:Q}
MAKE_ENV+=		FLEX=${TOOLS_CMD.flex:Q}
