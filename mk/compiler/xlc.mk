# $NetBSD: xlc.mk,v 1.27 2018/08/22 20:48:37 maya Exp $
#
# Copyright (c) 2005 The NetBSD Foundation, Inc.
# All rights reserved.
#
# This code is derived from software contributed to The NetBSD Foundation
# by Grant Beattie.
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
# This is the compiler definition for IBM's XL C/C++ compiler suite.
#
# User-settable variables:
#
# XLCBASE
#	The base directory where the compiler is installed.
#

.if !defined(COMPILER_XLC_MK)
COMPILER_XLC_MK=	defined

.include "../../mk/bsd.prefs.mk"

.if !defined(XLCBASE)
.  if exists(/usr/vacpp/README)
XLCBASE=	/usr/vacpp
.  elif exists(/usr/vac/README) || exists(/usr/vac/README.C)
XLCBASE=	/usr/vac
.  elif exists(/opt/ibmcmp/vacpp/6.0/README)
XLCBASE=	/opt/ibmcmp/vacpp/6.0
.  else
PKG_FAIL_REASON+=	"Cannot determine XLCBASE."
.  endif
.endif

# LANGUAGES.<compiler> is the list of supported languages by the
# compiler.
#
LANGUAGES.xlc=		# empty

_XLC_DIR=		${WRKDIR}/.xlc
_XLC_VARS=		# empty
.if exists(${XLCBASE}/bin/xlc)
LANGUAGES.xlc+=		c
_XLC_VARS+=		CC
_XLC_CC=		${_XLC_DIR}/bin/xlc
_ALIASES.CC=		cc xlc
_XLC_VARS+=		CPP
_XLC_CPP=		${_XLC_DIR}/bin/cpp
PKG_CPP:=		${_XLC_CPP}
CCPATH=			${XLCBASE}/bin/xlc
PKG_CC:=		${_XLC_CC}
.endif
.if exists(${XLCBASE}/bin/xlc++)
LANGUAGES.xlc+=		c++
_XLC_VARS+=		CXX
_XLC_CXX=		${_XLC_DIR}/bin/xlc++
_ALIASES.CXX=		c++ xlc++
CXXPATH=		${XLCBASE}/bin/xlc++
PKG_CXX:=		${_XLC_CXX}
.endif
.if exists(${XLCBASE}/bin/xlc_r)
_XLC_VARS+=		CC_R
_XLC_CC_R=		${_XLC_DIR}/bin/xlc_r
_ALIASES.CC_R=		cc_r xlc_r
CC_RPATH=		${XLCBASE}/bin/xlc_r
PKG_CC_R:=		${_XLC_CC_R}
CC_R?=			cc_r
.endif
.if exists(${XLCBASE}/bin/xlc++_r)
_XLC_VARS+=		CXX_R
_XLC_CXX_R=		${_XLC_DIR}/bin/xlc++_r
_ALIASES.CXX_R=		c++_r xlc++_r
CXX_RPATH=		${XLCBASE}/bin/xlc++_r
PKG_CXX_R:=		${_XLC_CXX_R}
CXX_R?=			c++_r
.endif
_COMPILER_STRIP_VARS+=	${_XLC_VARS}
_COMPILER_RPATH_FLAG=	-Wl,-R
_LINKER_RPATH_FLAG=	-R

.if exists(${CCPATH})
CC_VERSION_STRING!=	${CCPATH} -qversion 2>&1 | ${GREP} 'IBM XL C.*for' | ${SED} -e 's/^ *//' || ${TRUE}
CC_VERSION=		${CC_VERSION_STRING}
.else
CC_VERSION_STRING?=	${CC_VERSION}
CC_VERSION?=		IBM XL C
.endif

# Most packages assume alloca is available without #pragma alloca, so
# make it the default.
CFLAGS+=	-ma

# _LANGUAGES.<compiler> is ${LANGUAGES.<compiler>} restricted to the
# ones requested by the package in USE_LANGUAGES.
#
_LANGUAGES.xlc=		# empty
.for _lang_ in ${USE_LANGUAGES}
_LANGUAGES.xlc+=	${LANGUAGES.xlc:M${_lang_}}
.endfor

# Prepend the path to the compiler to the PATH.
.if !empty(_LANGUAGES.xlc)
PREPEND_PATH+=	${_XLC_DIR}/bin
.endif

override-tools: ${_XLC_CPP}
${_XLC_CPP}:
	${RUN}${MKDIR} ${.TARGET:H}
	${RUN}						\
	(${ECHO} '#!${TOOLS_SHELL}';			\
	 ${ECHO} 'exec ${XLCBASE}/bin/xlc -E "$$@"';	\
	) > ${.TARGET}
	${RUN}${CHMOD} +x ${.TARGET}

# Create compiler driver scripts in ${WRKDIR}.
.for _var_ in ${_XLC_VARS}
.  if !target(${_XLC_${_var_}})
override-tools: ${_XLC_${_var_}}
${_XLC_${_var_}}:
	${RUN}${MKDIR} ${.TARGET:H}
.    if !empty(COMPILER_USE_SYMLINKS:M[Yy][Ee][Ss])
	${RUN}${RM} -f ${.TARGET}
	${RUN}${LN} -s ${XLCBASE}/bin/${.TARGET:T} ${.TARGET}
.    else
	${RUN}					\
	(${ECHO} '#!${TOOLS_SHELL}';					\
	 ${ECHO} 'exec ${XLCBASE}/bin/${.TARGET:T} "$$@"';		\
	) > ${.TARGET}
	${RUN}${CHMOD} +x ${.TARGET}
.    endif
.    for _alias_ in ${_ALIASES.${_var_}:S/^/${.TARGET:H}\//}
	${RUN}					\
	if [ ! -x "${_alias_}" ]; then					\
		${LN} -f -s ${.TARGET} ${_alias_};			\
	fi
.    endfor
.  endif
.endfor

# Force the use of f2c-f77 for compiling Fortran.
_XLC_USE_F2C=	no
FCPATH=		/nonexistent
.if !exists(${FCPATH})
_XLC_USE_F2C=	yes
.endif
.if !empty(_XLC_USE_F2C:M[yY][eE][sS])
.  include "../../mk/compiler/f2c.mk"
.endif

.endif	# COMPILER_XLC_MK
