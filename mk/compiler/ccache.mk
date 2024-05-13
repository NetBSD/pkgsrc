# $NetBSD: ccache.mk,v 1.43 2024/05/13 00:32:34 gdt Exp $
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

# User-settable variables:
#
# CCACHE_BASE
#	The directory where ccache is installed. The build dependency on
#	devel/ccache is only added when this is ${TOOLBASE}.
#
#	Default: ${TOOLBASE}
#
# CCACHE_DIR
#	The directory where the cached compiler results are stored. By
#	default, they are stored inside WRKDIR, so they are lost after
#	a "make clean".
#
# CCACHE_LOGFILE
#       If set to a file path, ccache will write information on what it is
#       doing to the specified file. This is useful for tracking down
#       problems.
#
#
# CCACHE_RECACHE
#
#       If set, instruct ccache to not use cached values, but to store
#       the results.  This can be used temporarily to recover from
#       cache corruption, or to verify that removing cache corruption
#       as a possibility does not change the problem one is chasing.
#
# Package-settable variables:
#
# IGNORE_CCACHE
#	Can be set to "yes" for packages that have problems with ccache.
#
# Keywords: ccache
#

# \todo We now have two versions of ccache, one with fairly light
# dependencies and one with heavier dependencies (C++17, cmake, ruby).
# Obviously some people are going to prefer one and some the other,
# and thus the right approach is to have a CCACHE_TYPE variable that
# can mean devel/ccache3 or devel/ccache, and to use that to control
# both the circular dependency list and the package that is depended
# on.  For now (meaning the 2022Q4 branch), just set to ccache3.

.if !defined(COMPILER_CCACHE_MK)
COMPILER_CCACHE_MK=	defined

_VARGROUPS+=		ccache
_USER_VARS.ccache=	CCACHE_BASE CCACHE_DIR CCACHE_LOGFILE CCACHE_RECACHE
_PKG_VARS.ccache=	IGNORE_CCACHE

.include "../bsd.fast.prefs.mk"

CCACHE_BASE?=	${TOOLBASE}
CCACHE_DIR?=	${WRKDIR}/.ccache-cache

_USE_CCACHE=	yes

# List of packages that ccache may directly or indirectly depend upon,
# and thus cannot inversely depend on ccache.
_CCACHE_CIRCULAR_DEPENDENCY_PACKAGES=	\
	archivers/gzip			\
	devel/ccache3			\
	devel/ccache			\
	devel/distcc			\
	devel/libtool-base		\
	devel/nbpatch			\
	devel/zlib			\
	net/tnftp			\
	pkgtools/cwrappers		\
	pkgtools/digest			\
	pkgtools/pkg_install-info	\
	sysutils/checkperms

# break circular dependencies
.if ${CCACHE_BASE} == ${TOOLBASE} &&	\
	!empty(_CCACHE_CIRCULAR_DEPENDENCY_PACKAGES:M${PKGPATH})
_USE_CCACHE=	no
MAKEFLAGS+=	_USE_CCACHE=${_USE_CCACHE}
.endif

.if defined(IGNORE_CCACHE)
_USE_CCACHE=	no
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
_USE_CCACHE=	no
.endif

.if ${_USE_CCACHE} == "yes"

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

PREPEND_PATH+=	${_CCACHE_DIR}/bin

# Add the dependency on ccache.
.  if ${CCACHE_BASE} == ${TOOLBASE}
TOOL_DEPENDS+=	ccache-[0-9]*:../../devel/ccache3
.  endif

# Override the compiler-specific hash with the version string for the
# compiler.
#
PKGSRC_MAKE_ENV+=	CCACHE_COMPILERCHECK=echo\ ${CC_VERSION_STRING:Q}
PKGSRC_MAKE_ENV+=	CCACHE_DIR=${CCACHE_DIR:Q}
PKGSRC_MAKE_ENV+=	CCACHE_PATH=${CCPATH:H}:${CXXPATH:H}:${CPPPATH:H}
.ifdef CCACHE_LOGFILE
PKGSRC_MAKE_ENV+=	CCACHE_LOGFILE=${CCACHE_LOGFILE:Q}
.endif
.ifdef CCACHE_RECACHE
PKGSRC_MAKE_ENV+=	CCACHE_RECACHE=true
.endif

# Create symlinks for the compiler into ${WRKDIR}.
.  for _var_ in ${_CCACHE_VARS}
.    if !target(${_CCACHE_${_var_}})
override-tools: ${_CCACHE_${_var_}}
${_CCACHE_${_var_}}:
	${RUN}${MKDIR} ${.TARGET:H}
	${RUN}					\
	${LN} -fs ${CCACHE_BASE}/bin/ccache ${.TARGET}
.      for _alias_ in ${_ALIASES.${_var_}:S/^/${.TARGET:H}\//}
	${RUN}					\
	if [ ! -x "${_alias_}" ]; then					\
		${LN} -fs ${CCACHE_BASE}/bin/ccache ${_alias_};		\
	fi
.      endfor
.    endif
.  endfor
.endif	# _USE_CCACHE == "yes"

.endif	# COMPILER_CCACHE_MK
