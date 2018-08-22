# $NetBSD: f2c.mk,v 1.19 2018/08/22 20:48:37 maya Exp $
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

.if !defined(COMPILER_F2C_MK)
COMPILER_F2C_MK=	defined

.include "../../mk/bsd.prefs.mk"

# LANGUAGES.<compiler> is the list of supported languages by the compiler.
# _LANGUAGES.<compiler> is ${LANGUAGES.<compiler>} restricted to the ones
# requested by the package in USE_LANGUAGES.
#
LANGUAGES.f2c=	fortran fortran77
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
USE_LANGUAGES+=		c

_F2C_DIR=	${WRKDIR}/.f2c
_F2C_VARS=	# empty
.  if !empty(_LANGUAGES.f2c:Mfortran) || !empty(_LANGUAGES.f2c:Mfortran77)
PKG_FC?=	${FC}
_F2C_VARS+=	FC
_F2C_FC:=	${_F2C_DIR}/bin/${PKG_FC:T}
_ALIASES.FC+=	f77 g77 f2c-f77
FCPATH=		${LOCALBASE}/bin/f2c-f77
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

# Dependencies:
TOOL_DEPENDS+=	f2c>=20090411nb2:../../lang/f2c # translator

.if empty(PKGPATH:Mdevel/libtool-base) && empty(PKGPATH:Mcross/cross-libtool-base) # See below
.  include "../../devel/libf2c/buildlink3.mk" # library
.endif

.  if defined(F2C_DIR) && !empty(F2C_DIR)
PKGSRC_MAKE_ENV+=	F2C_DIR=${F2C_DIR:Q}
.  endif

# libtool-base is special as it only needs f77 to extract linker flags etc.
.if !empty(PKGPATH:Mdevel/libtool-base) || !empty(PKGPATH:Mcross/cross-libtool-base)
pre-configure: fake-f2c-libs

_WRAP_EXTRA_ARGS.FC+=	-L${WRKDIR}/.f2c/lib -I${WRKDIR}/.f2c/include

fake-f2c-libs:
	${MKDIR} ${WRKDIR}/.f2c/include
	${MKDIR} ${WRKDIR}/.f2c/lib
	${ECHO} 'int main(void) { return 0; }' > ${WRKDIR}/.f2c/lib/main.c
	${CC} -c -o ${WRKDIR}/.f2c/lib/main.o ${WRKDIR}/.f2c/lib/main.c
	${AR} cq ${WRKDIR}/.f2c/lib/libf2c.a ${WRKDIR}/.f2c/lib/main.o
	${RANLIB} ${WRKDIR}/.f2c/lib/libf2c.a
	${TOUCH} ${WRKDIR}/.f2c/include/f2c.h
.endif

# Create symlinks for the compiler into ${WRKDIR}.
.  for _var_ in ${_F2C_VARS}
.    if !target(${_F2C_${_var_}})
override-tools: ${_F2C_${_var_}}
${_F2C_${_var_}}:
	${RUN}${MKDIR} ${.TARGET:H}
	${RUN}					\
	${LN} -fs ${LOCALBASE}/bin/f2c-f77 ${.TARGET}
.      for _alias_ in ${_ALIASES.${_var_}:S/^/${.TARGET:H}\//}
	${RUN}					\
	if [ ! -x "${_alias_}" ]; then					\
		${LN} -fs ${LOCALBASE}/bin/f2c-f77 ${_alias_};		\
	fi
.      endfor
.    endif
.  endfor
.endif	# _USE_F2C == "yes"

.endif	# COMPILER_F2C_MK
