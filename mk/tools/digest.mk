# $NetBSD: digest.mk,v 1.3 2018/08/22 20:48:37 maya Exp $
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
#

#
# This Makefile fragment defines additional variables that are used
# by packages that need digest.
#
# Optional variables that may be defined by the package are:
#
#	DIGEST_REQD is the minimum version of digest required.
#
# This file needs to be included before replace.mk as it uses the
# replace.mk magic to set the TOOLS_DIGEST and DIGEST variables.
#

DIGEST_REQD?=		20010302

.if !defined(TOOLS_IGNORE.digest) && !empty(USE_TOOLS:C/:.*//:Mdigest)
.  if !empty(PKGPATH:Mpkgtools/digest)
MAKEFLAGS+=		TOOLS_IGNORE.digest=
.  else
.    if defined(TOOLS_PLATFORM.digest) && !empty(TOOLS_PLATFORM.digest)
_TOOLS_USE_PKGSRC.digest?=	no
.      if !defined(_TOOLS_VERSION.digest)
_TOOLS_VERSION.digest!=		\
	${TOOLS_PLATFORM.digest} -V 2>/dev/null || ${ECHO} 20010301
_TOOLS_USE_PKGSRC.digest!=						\
	if ${PKG_ADMIN} pmatch "digest>="${DIGEST_REQD:Q}		\
			digest-${_TOOLS_VERSION.digest:Q}; then		\
		${ECHO} no;						\
	else								\
		${ECHO} yes;						\
	fi
.      endif
MAKEVARS+=	_TOOLS_USE_PKGSRC.digest
.    else
_TOOLS_USE_PKGSRC.digest=	yes
.    endif
.    if !empty(_TOOLS_USE_PKGSRC.digest:M[yY][eE][sS])
TOOLS_DEPENDS.digest?=	digest>=${DIGEST_REQD}:../../pkgtools/digest
TOOLS_CREATE+=		digest
TOOLS_PATH.digest=	${LOCALBASE}/bin/digest
.    endif
.  endif
.endif
