# $NetBSD: f2c.mk,v 1.10 2008/02/07 20:59:05 rillig Exp $
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

.if !defined(COMPILER_F2C_MK)
COMPILER_F2C_MK=	defined

.include "../../mk/bsd.prefs.mk"

USE_LANGUAGES+=		c

.if !empty(PKGPATH:Mlang/f2c) || !empty(PKGPATH:Mdevel/patch) || \
    !empty(PKGPATH:Mdevel/libtool-base)
IGNORE_F2C=	yes
MAKEFLAGS+=	IGNORE_F2C=yes
.endif

.if defined(IGNORE_F2C)
_USE_F2C=	NO
.endif

# LANGUAGES.<compiler> is the list of supported languages by the compiler.
# _LANGUAGES.<compiler> is ${LANGUAGES.<compiler>} restricted to the ones
# requested by the package in USE_LANGUAGES.
#
LANGUAGES.f2c=	fortran
_LANGUAGES.f2c=	# empty
.for _lang_ in ${USE_LANGUAGES}
_LANGUAGES.f2c+=	${LANGUAGES.f2c:M${_lang_}}
.endfor
.if empty(_LANGUAGES.f2c)
_USE_F2C=	NO
.endif

.if !defined(_USE_F2C)
_USE_F2C=	YES
.endif

.if !empty(_USE_F2C:M[yY][eE][sS])
EVAL_PREFIX+=		_F2CBASE=f2c
_F2CBASE_DEFAULT=	${LOCALBASE}

_F2C_DIR=	${WRKDIR}/.f2c
_F2C_VARS=	# empty
.  if !empty(_LANGUAGES.f2c:Mfortran)
PKG_FC?=	${FC}
_F2C_VARS+=	FC
_F2C_FC:=	${_F2C_DIR}/bin/${PKG_FC:T}
_ALIASES.FC+=	f77 g77 f2c-f77
FCPATH=		${_F2CBASE}/bin/f2c-f77
PKG_FC:=	${_F2C_FC}
#
# The f2c-f77 shell script invokes the C compiler, so ensure that it finds
# the cc wrapper for proper transformations.
#
# XXX This shouldn't really be leaking into here, as it breaks encapsulation.
# XXX It should really be handled within the wrapper framework.
#
_WRAP_ENV.FC=	PATH="${WRAPPER_BINDIR}:${_WRAP_PATH}"; export PATH
.  endif

# Prepend the path the to the compiler to the PATH
.  if !empty(_LANGUAGES.f2c)
PREPEND_PATH+=	${_F2C_DIR}/bin
.  endif

# Add the dependency on f2c.
.  include "../../lang/f2c/buildlink3.mk"

.  if defined(F2C_DIR) && !empty(F2C_DIR)
PKGSRC_MAKE_ENV+=	F2C_DIR=${F2C_DIR:Q}
.  endif

# Create symlinks for the compiler into ${WRKDIR}.
.  for _var_ in ${_F2C_VARS}
.    if !target(${_F2C_${_var_}})
override-tools: ${_F2C_${_var_}}
${_F2C_${_var_}}:
	${RUN}${MKDIR} ${.TARGET:H}
	${RUN}					\
	${LN} -fs ${_F2CBASE}/bin/f2c-f77 ${.TARGET}
.      for _alias_ in ${_ALIASES.${_var_}:S/^/${.TARGET:H}\//}
	${RUN}					\
	if [ ! -x "${_alias_}" ]; then					\
		${LN} -fs ${_F2CBASE}/bin/f2c-f77 ${_alias_};		\
	fi
.      endfor
.    endif
.  endfor
.endif	# _USE_F2C == "yes"

.endif	# COMPILER_F2C_MK
