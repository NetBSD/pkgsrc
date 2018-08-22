# $NetBSD: gfortran.mk,v 1.10 2018/08/22 20:48:37 maya Exp $
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

.if !defined(COMPILER_GFORTRAN_MK)
COMPILER_GFORTRAN_MK=	defined

.include "../../mk/bsd.prefs.mk"

GFORTRAN_VERSION?=	48

.if !empty(PKGPATH:Mlang/gcc${GFORTRAN_VERSION}) || !empty(PKGPATH:Mdevel/patch) || \
    !empty(PKGPATH:Mdevel/libtool-base)
IGNORE_GFORTRAN=	yes
MAKEFLAGS+=		IGNORE_GFORTRAN=yes
.endif

.if defined(IGNORE_GFORTRAN)
_USE_GFORTRAN=	NO
.endif

# LANGUAGES.<compiler> is the list of supported languages by the compiler.
# _LANGUAGES.<compiler> is ${LANGUAGES.<compiler>} restricted to the ones
# requested by the package in USE_LANGUAGES.
#
LANGUAGES.gfortran=	fortran fortran77
_LANGUAGES.gfortran=	# empty
.for _lang_ in ${USE_LANGUAGES}
_LANGUAGES.gfortran+=	${LANGUAGES.gfortran:M${_lang_}}
.endfor
.if empty(_LANGUAGES.gfortran)
_USE_GFORTRAN=	NO
.endif

.if !defined(_USE_GFORTRAN)
_USE_GFORTRAN=	YES
.endif

.if !empty(_USE_GFORTRAN:M[yY][eE][sS])
_GFORTRANBASE=	${LOCALBASE}/gcc${GFORTRAN_VERSION}
FC=		gfortran

_GFORTRAN_DIR=	${WRKDIR}/.gfortran
_GFORTRAN_VARS=	# empty
.  if !empty(_LANGUAGES.gfortran:Mfortran) || \
      !empty(_LANGUAGES.gfortran:Mfortran77)
PKG_FC?=	${FC}
_GFORTRAN_VARS+=	FC
_GFORTRAN_FC:=	${_GFORTRAN_DIR}/bin/${PKG_FC:T}
_ALIASES.FC+=	f77 g77 g95 gfortran
FCPATH=		${_GFORTRANBASE}/bin/gfortran
PKG_FC:=	${_GFORTRAN_FC}
.  endif

# Prepend the path the to the compiler to the PATH
.  if !empty(_LANGUAGES.gfortran)
PREPEND_PATH+=	${_GFORTRAN_DIR}/bin
.  endif

# Add the dependency on gfortran.
BUILDLINK_DEPMETHOD.gcc${GFORTRAN_VERSION}=	full
.  include "../../lang/gcc${GFORTRAN_VERSION}/buildlink3.mk"

.  if defined(GFORTRAN_DIR) && !empty(GFORTRAN_DIR)
PKGSRC_MAKE_ENV+=	GFORTRAN_DIR=${GFORTRAN_DIR:Q}
.  endif

# Create symlinks for the compiler into ${WRKDIR}.
.  for _var_ in ${_GFORTRAN_VARS}
.    if !target(${_GFORTRAN_${_var_}})
override-tools: ${_GFORTRAN_${_var_}}
${_GFORTRAN_${_var_}}:
	${RUN}${MKDIR} ${.TARGET:H}
	${RUN}					\
	${LN} -fs ${_GFORTRANBASE}/bin/gfortran ${.TARGET}
.      for _alias_ in ${_ALIASES.${_var_}:S/^/${.TARGET:H}\//}
	${RUN}					\
	if [ ! -x "${_alias_}" ]; then					\
		${LN} -fs ${_GFORTRANBASE}/bin/gfortran ${_alias_};		\
	fi
.      endfor
.    endif
.  endfor
.endif	# _USE_GFORTRAN == "yes"

.endif	# COMPILER_GFORTRAN_MK
