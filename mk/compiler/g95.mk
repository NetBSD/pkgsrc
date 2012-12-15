# $NetBSD: g95.mk,v 1.4 2012/12/15 21:23:31 markd Exp $
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

.if !defined(COMPILER_G95_MK)
COMPILER_G95_MK=	defined

.include "../../mk/bsd.prefs.mk"

.if !empty(PKGPATH:Mlang/g95) || !empty(PKGPATH:Mdevel/patch) || \
    !empty(PKGPATH:Mdevel/libtool-base)
IGNORE_G95=	yes
MAKEFLAGS+=	IGNORE_G95=yes
.endif

.if defined(IGNORE_G95)
_USE_G95=	NO
.endif

# LANGUAGES.<compiler> is the list of supported languages by the compiler.
# _LANGUAGES.<compiler> is ${LANGUAGES.<compiler>} restricted to the ones
# requested by the package in USE_LANGUAGES.
#
LANGUAGES.g95=	fortran fortran77
_LANGUAGES.g95=	# empty
.for _lang_ in ${USE_LANGUAGES}
_LANGUAGES.g95+=	${LANGUAGES.g95:M${_lang_}}
.endfor
.if empty(_LANGUAGES.g95)
_USE_G95=	NO
.endif

.if !defined(_USE_G95)
_USE_G95=	YES
.endif

.if !empty(_USE_G95:M[yY][eE][sS])
EVAL_PREFIX+=		_G95BASE=g95
_G95BASE_DEFAULT=	${LOCALBASE}
FC=		g95

_G95_DIR=	${WRKDIR}/.g95
_G95_VARS=	# empty
.  if !empty(_LANGUAGES.g95:Mfortran) || \
      !empty(_LANGUAGES.g95:Mfortran77)
PKG_FC?=	${FC}
_G95_VARS+=	FC
_G95_FC:=	${_G95_DIR}/bin/${PKG_FC:T}
_ALIASES.FC+=	f77 g77 g95
FCPATH=		${_G95BASE}/bin/g95
PKG_FC:=	${_G95_FC}
.  endif

# Prepend the path the to the compiler to the PATH
.  if !empty(_LANGUAGES.g95)
PREPEND_PATH+=	${_G95_DIR}/bin
.  endif

# Add the dependency on g95.
.  include "../../lang/g95/buildlink3.mk"

.  if defined(G95_DIR) && !empty(G95_DIR)
PKGSRC_MAKE_ENV+=	G95_DIR=${G95_DIR:Q}
.  endif

# Create symlinks for the compiler into ${WRKDIR}.
.  for _var_ in ${_G95_VARS}
.    if !target(${_G95_${_var_}})
override-tools: ${_G95_${_var_}}
${_G95_${_var_}}:
	${RUN}${MKDIR} ${.TARGET:H}
	${RUN}					\
	${LN} -fs ${_G95BASE}/bin/g95 ${.TARGET}
.      for _alias_ in ${_ALIASES.${_var_}:S/^/${.TARGET:H}\//}
	${RUN}					\
	if [ ! -x "${_alias_}" ]; then					\
		${LN} -fs ${_G95BASE}/bin/g95 ${_alias_};		\
	fi
.      endfor
.    endif
.  endfor
.endif	# _USE_G95 == "yes"

.endif	# COMPILER_G95_MK
