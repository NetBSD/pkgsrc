# $NetBSD: bison.mk,v 1.2 2018/08/22 20:48:37 maya Exp $
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

BISON_REQD?=		1.875

# If the package does explicitly request bison as a tool, then determine if the
# platform-provided bison's version is at least ${BISON_REQD}.  If it isn't, then
# tell the tools framework to use the pkgsrc bison.
#

.if !empty(USE_TOOLS:C/:.*//:Mbison*) && \
    defined(TOOLS_PLATFORM.bison) && !empty(TOOLS_PLATFORM.bison)
.  if !defined(_TOOLS_USE_PKGSRC.bison)
_TOOLS_VERSION.bison!=							\
	${TOOLS_PLATFORM.bison} --version |				\
	${SED} -n -e 's/^bison.* \([0-9]\..*\)/\1/p'
_TOOLS_PKG.bison=		bison-${_TOOLS_VERSION.bison}
_TOOLS_USE_PKGSRC.bison=	no
.    for _dep_ in bison>=${BISON_REQD}
.      if !empty(_TOOLS_USE_PKGSRC.bison:M[nN][oO])
_TOOLS_USE_PKGSRC.bison!=						\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${_TOOLS_PKG.bison:Q}; then \
		${ECHO} no;						\
	else								\
		${ECHO} yes;						\
	fi
.      endif
.    endfor
.  endif
MAKEVARS+=	_TOOLS_USE_PKGSRC.bison
.endif

CONFIGURE_ENV+=		BISON=${TOOLS_CMD.bison:Q}
MAKE_ENV+=		BISON=${TOOLS_CMD.bison:Q}
