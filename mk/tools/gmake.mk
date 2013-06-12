# $NetBSD: gmake.mk,v 1.3 2013/06/12 20:37:43 riastradh Exp $
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

GMAKE_REQD?=		3.81

# If the package does explicitly request gmake as a tool, then determine if the
# platform-provided gmake's version is at least ${GMAKE_REQD}.  If it isn't, then
# tell the tools framework to use the pkgsrc gmake.
#

.if !empty(USE_TOOLS:C/:.*//:Mgmake) && \
    defined(TOOLS_PLATFORM.gmake) && !empty(TOOLS_PLATFORM.gmake)
.  if !defined(_TOOLS_USE_PKGSRC.gmake)
_TOOLS_VERSION.gmake!=							\
	${TOOLS_PLATFORM.gmake} --version |				\
	${AWK} '{print $$3; exit}'
_TOOLS_PKG.gmake=		gmake-${_TOOLS_VERSION.gmake}
_TOOLS_USE_PKGSRC.gmake=	no
.    for _dep_ in gmake>=${GMAKE_REQD}
.      if !empty(_TOOLS_USE_PKGSRC.gmake:M[nN][oO])
_TOOLS_USE_PKGSRC.gmake!=						\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${_TOOLS_PKG.gmake:Q}; then \
		${ECHO} no;						\
	else								\
		${ECHO} yes;						\
	fi
.      endif
.    endfor
.  endif
MAKEVARS+=	_TOOLS_USE_PKGSRC.gmake
.endif

# XXX Kludge to prevent pkgsrc's internal variable TARGET_ARCH for
# cross-compilation from leaking into gmake's environment, where it
# will break the default rules.  Remove either when we start using
# `env -i' for the build phase or when we replace TARGET_ARCH by
# TARGET_MACHINE_PLATFORM.
.if defined(TARGET_ARCH)
MAKE_ENV+=	TARGET_ARCH=
.endif
