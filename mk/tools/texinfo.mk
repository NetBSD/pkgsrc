# $NetBSD: texinfo.mk,v 1.12 2018/08/22 20:48:37 maya Exp $
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

TEXINFO_REQD?=		3.12

# If the package doesn't explicitly request makeinfo as a tool, then
# create a "broken" makeinfo tool to fool GNU configure scripts into
# believing that makeinfo is broken on ths sytem.  It will return non-zero
# if invoked as "makeinfo --version".  Otherwise, it will just touch the
# appropriate output file to satisfy any make dependencies.
#
# If the package does explicitly request makeinfo as a tool, then
# determine if the platform-provided makeinfo's version is at least
# ${TEXINFO_REQD}.  If it isn't, then tell the tools framework to use
# the pkgsrc makeinfo.
#
.if empty(USE_TOOLS:C/:.*//:Mmakeinfo)
TOOLS_CREATE+=		makeinfo
TOOLS_PATH.makeinfo=	${PKGSRCDIR}/mk/gnu-config/missing
TOOLS_SCRIPT.makeinfo=	for arg in "$$@"; do case "$$arg" in --version) exit 1 ;; esac; done; ${TOOLS_PATH.makeinfo} makeinfo "$$@"
.elif defined(TOOLS_PLATFORM.makeinfo) && !empty(TOOLS_PLATFORM.makeinfo)
.  if !defined(_TOOLS_USE_PKGSRC.makeinfo)
_TOOLS_VERSION.makeinfo!=						\
	${TOOLS_PLATFORM.makeinfo} --version |				\
	${AWK} '{ print $$4; exit; }'
_TOOLS_PKG.makeinfo=		gtexinfo-${_TOOLS_VERSION.makeinfo}
_TOOLS_USE_PKGSRC.makeinfo=	no
.    for _dep_ in gtexinfo>=${TEXINFO_REQD}
.      if !empty(_TOOLS_USE_PKGSRC.makeinfo:M[nN][oO])
_TOOLS_USE_PKGSRC.makeinfo!=						\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${_TOOLS_PKG.makeinfo:Q}; then \
		${ECHO} no;						\
	else								\
		${ECHO} yes;						\
	fi
.      endif
.    endfor
.  endif
MAKEVARS+=	_TOOLS_USE_PKGSRC.makeinfo
.endif

CONFIGURE_ENV+=		INSTALL_INFO=${TOOLS_CMD.install-info:Q}
MAKE_ENV+=		INSTALL_INFO=${TOOLS_CMD.install-info:Q}
CONFIGURE_ENV+=		MAKEINFO=${TOOLS_CMD.makeinfo:Q}
MAKE_ENV+=		MAKEINFO=${TOOLS_CMD.makeinfo:Q}
