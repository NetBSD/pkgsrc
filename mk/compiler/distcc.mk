# $NetBSD: distcc.mk,v 1.33 2018/08/22 20:48:37 maya Exp $
#
# Copyright (c) 2004 The NetBSD Foundation, Inc.
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

.if !defined(COMPILER_DISTCC_MK)
COMPILER_DISTCC_MK=	defined

.include "../../mk/bsd.prefs.mk"

.if !empty(PKGPATH:Mdevel/distcc)
IGNORE_DISTCC=	yes
MAKEFLAGS+=	IGNORE_DISTCC=yes
.endif

.if defined(IGNORE_DISTCC)
_USE_DISTCC=	NO
.endif

# LANGUAGES.<compiler> is the list of supported languages by the compiler.
# _LANGUAGES.<compiler> is ${LANGUAGES.<compiler>} restricted to the ones
# requested by the package in USE_LANGUAGES.
#
LANGUAGES.distcc=	c c++
_LANGUAGES.distcc=	# empty
.for _lang_ in ${USE_LANGUAGES}
_LANGUAGES.distcc+=	${LANGUAGES.distcc:M${_lang_}}
.endfor
.if empty(_LANGUAGES.distcc)
_USE_DISTCC=	NO
.endif

.if !defined(_USE_DISTCC)
_USE_DISTCC=	YES
.endif

.if !empty(_USE_DISTCC:M[yY][eE][sS])
_DISTCC_DIR=	${WRKDIR}/.distcc
_DISTCC_VARS=	# empty
.  if !empty(_LANGUAGES.distcc:Mc)
PKG_CC?=	${CC}
_DISTCC_VARS+=	CC
_DISTCC_CC:=	${_DISTCC_DIR}/bin/${PKG_CC:T}
_ALIASES.CC+=	cc
PKG_CC:=	${_DISTCC_CC}
.  endif
.  if !empty(_LANGUAGES.distcc:Mc++)
PKG_CXX?=	${CXX}
_DISTCC_VARS+=	CXX
_DISTCC_CXX:=	${_DISTCC_DIR}/bin/${PKG_CXX:T}
_ALIASES.CXX+=	c++
PKG_CXX:=	${_DISTCC_CXX}
.  endif

# Prepend the path to the compiler to the PATH.
.  if !empty(_LANGUAGES.distcc)
PREPEND_PATH+=	${_DISTCC_DIR}/bin
.  endif

# Add the dependency on distcc.
TOOL_DEPENDS+=	distcc-[0-9]*:../../devel/distcc
DISTCCBASE?=	${PREFIX}

.  if defined(DISTCC_HOSTS) && !empty(DISTCC_HOSTS)
PKGSRC_MAKE_ENV+=	DISTCC_HOSTS=${DISTCC_HOSTS:Q}
.  endif
.  if defined(DISTCC_SSH) && !empty(DISTCC_SSH)
PKGSRC_MAKE_ENV+=	DISTCC_SSH=${DISTCC_SSH:Q}
.  endif
.  if defined(DISTCC_VERBOSE) && !empty(DISTCC_VERBOSE)
PKGSRC_MAKE_ENV+=	DISTCC_VERBOSE=${DISTCC_VERBOSE:Q}
.  endif

# Create symlinks for the compiler into ${WRKDIR}.
.  for _var_ in ${_DISTCC_VARS}
.    if !target(${_DISTCC_${_var_}})
override-tools: ${_DISTCC_${_var_}}
${_DISTCC_${_var_}}:
	${RUN}${MKDIR} ${.TARGET:H}
	${RUN}					\
	${LN} -fs ${DISTCCBASE}/bin/distcc ${.TARGET}
.      for _alias_ in ${_ALIASES.${_var_}:S/^/${.TARGET:H}\//}
	${RUN}					\
	if [ ! -x "${_alias_}" ]; then					\
		${LN} -fs ${DISTCCBASE}/bin/distcc ${_alias_};		\
	fi
.      endfor
.    endif
.  endfor
.endif	# _USE_DISTCC == "yes"

.endif # COMPILER_DISTCC_MK
