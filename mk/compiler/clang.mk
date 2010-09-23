# $NetBSD: clang.mk,v 1.1 2010/09/23 22:26:07 ahoka Exp $
#
# This is the compiler definition for the clang compiler.
#
# User-settable variables:
#
# CLANGBASE
#	The base directory where the compiler is installed.
#

.if !defined(COMPILER_CLANG_MK)
COMPILER_CLANG_MK=	defined

# Add the dependency on clang
# TODO: may be installed already, check for this
BUILD_DEPENDS+= clang-[0-9]*:../../lang/clang

.include "../../mk/bsd.prefs.mk"

CLANGBASE?=		${PREFIX}

LANGUAGES.clang=	# empty

#_CLANG_DIR=		${WRKDIR}/.clang
_CLANG_DIR=		${CLANGBASE}/bin
_CLANG_VARS=		# empty

.if exists(${CLANGBASE}/bin/clang)
LANGUAGES.hp+=		c
_CLANG_VARS+=		CC
_CLANG_CC=		${_CLANG_DIR}/clang
_ALIASES.CC=		cc gcc c89 c99
CCPATH=			${CLANGBASE}/bin/clang
PKG_CC:=		${_CLANG_CC}
.endif

# NOTE: clang C++ support is still experimental, enable later
.if exists(${CLANGBASE}/bin/clang++)
#LANGUAGES.hp+=		c++
#_CLANG_VARS+=		CXX
#_CLANG_CXX=		${_CLANG_DIR}/clang++
#_ALIASES.CXX=		c++ g++
#CXXPATH=		${CLANGBASE}/bin/clang++
#PKG_CXX:=		${_CLANG_CXX}
.endif

_COMPILER_STRIP_VARS+=	${_CLANG_VARS}

# Mimic GCC behaviour by defaulting to C89
#.if !empty(USE_LANGUAGES:Mc99)
#_WRAP_EXTRA_ARGS.CC+=	-std=gnu99
#.else
#_WRAP_EXTRA_ARGS.CC+=	-std=gnu89
#.endif

_LINKER_RPATH_FLAG=	-rpath,

_COMPILER_RPATH_FLAG=	-Wl,-rpath,

.if exists(${CCPATH})
CC_VERSION_STRING!=	${CCPATH} -v 2>&1
CC_VERSION!=		${CCPATH} -dumpversion 2>&1
.else
CC_VERSION_STRING?=	${CC_VERSION}
CC_VERSION?=		clang
.endif

# _LANGUAGES.<compiler> is ${LANGUAGES.<compiler>} restricted to the
# ones requested by the package in USE_LANGUAGES.
#
_LANGUAGES.clang=	# empty
.for _lang_ in ${USE_LANGUAGES}
_LANGUAGES.clang+=	${LANGUAGES.clang:M${_lang_}}
.endfor

.endif	# COMPILER_CLANG_MK
