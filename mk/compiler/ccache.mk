# $NetBSD: ccache.mk,v 1.27 2006/07/21 14:27:56 jlam Exp $
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

.if !defined(COMPILER_CCACHE_MK)
COMPILER_CCACHE_MK=	defined

.include "../../mk/bsd.prefs.mk"

.if !empty(PKGPATH:Mdevel/ccache) || !empty(PKGPATH:Mdevel/patch)
IGNORE_CCACHE=	yes
MAKEFLAGS+=	IGNORE_CCACHE=yes
.endif

.if defined(IGNORE_CCACHE)
_USE_CCACHE=	NO
.endif

# LANGUAGES.<compiler> is the list of supported languages by the compiler.
# _LANGUAGES.<compiler> is ${LANGUAGES.<compiler>} restricted to the ones
# requested by the package in USE_LANGUAGES.
# 
LANGUAGES.ccache=	c c++
_LANGUAGES.ccache=	# empty
.for _lang_ in ${USE_LANGUAGES}
_LANGUAGES.ccache+=	${LANGUAGES.ccache:M${_lang_}}
.endfor
.if empty(_LANGUAGES.ccache)
_USE_CCACHE=	NO
.endif

.if !defined(_USE_CCACHE)
_USE_CCACHE=	YES
.endif

.if !empty(_USE_CCACHE:M[yY][eE][sS])
EVAL_PREFIX+=		_CCACHEBASE=ccache
_CCACHEBASE_DEFAULT=	${LOCALBASE}

_CCACHE_DIR=	${WRKDIR}/.ccache
_CCACHE_VARS=	# empty
.  if !empty(_LANGUAGES.ccache:Mc)
PKG_CC?=	${CC}
_CCACHE_VARS+=	CC
_CCACHE_CC:=	${_CCACHE_DIR}/bin/${PKG_CC:T}
_ALIASES.CC+=	cc
PKG_CC:=	${_CCACHE_CC}
.  endif
.  if !empty(_LANGUAGES.ccache:Mc++)
PKG_CXX?=	${CXX}
_CCACHE_VARS+=	CXX
_CCACHE_CXX:=	${_CCACHE_DIR}/bin/${PKG_CXX:T}
_ALIASES.CXX+=	c++
PKG_CXX:=	${_CCACHE_CXX}
.  endif

# Prepend the path the to the compiler to the PATH
.  if !empty(_LANGUAGES.ccache)
PREPEND_PATH+=	${_CCACHE_DIR}/bin
.  endif

# Add the dependency on ccache.
BUILD_DEPENDS+=	ccache-[0-9]*:../../devel/ccache

# Override the compiler-specific hash with the version string for the
# compiler.
#
PKGSRC_MAKE_ENV+=	CCACHE_HASHCC=${CC_VERSION_STRING:Q}

.  if defined(CCACHE_DIR) && !empty(CCACHE_DIR)
PKGSRC_MAKE_ENV+=	CCACHE_DIR=${CCACHE_DIR:Q}
.  endif

# Create symlinks for the compiler into ${WRKDIR}.
.  for _var_ in ${_CCACHE_VARS}
.    if !target(${_CCACHE_${_var_}})
override-tools: ${_CCACHE_${_var_}}
${_CCACHE_${_var_}}:
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${LN} -fs ${_CCACHEBASE}/bin/ccache ${.TARGET}
.      for _alias_ in ${_ALIASES.${_var_}:S/^/${.TARGET:H}\//}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	if [ ! -x "${_alias_}" ]; then					\
		${LN} -fs ${_CCACHEBASE}/bin/ccache ${_alias_};		\
	fi
.      endfor
.    endif
.  endfor
.endif	# _USE_CCACHE == "yes"

.endif	# COMPILER_CCACHE_MK
