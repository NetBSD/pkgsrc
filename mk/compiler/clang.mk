# $NetBSD: clang.mk,v 1.4 2010/12/26 08:12:30 adam Exp $
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
#BUILD_DEPENDS+= clang-[0-9]*:../../lang/clang

.include "../../mk/bsd.prefs.mk"

CLANGBASE?=		${LOCALBASE}
LANGUAGES.clang=	# empty

.if exists(${CLANGBASE}/bin/clang)
LANGUAGES.clang+=	c objc
_COMPILER_STRIP_VARS+=	CC
CCPATH=			${CLANGBASE}/bin/clang
PKG_CC:=		${CCPATH}
.endif

.if exists(${CLANGBASE}/bin/clang++)
LANGUAGES.clang+=	c++
_COMPILER_STRIP_VARS+=	CXX
CXXPATH=		${CLANGBASE}/bin/clang++
PKG_CXX:=		${CXXPATH}
.endif

# Mimic GCC behaviour by defaulting to C89
#.if !empty(USE_LANGUAGES:Mc99)
#_WRAP_EXTRA_ARGS.CC+=	-std=gnu99
#.else
#_WRAP_EXTRA_ARGS.CC+=	-std=gnu89
#.endif

.if exists(${CCPATH})
CC_VERSION_STRING!=	${CCPATH} -v 2>&1
CC_VERSION!=		${CCPATH} -dumpversion 2>&1
.else
CC_VERSION_STRING?=	${CC_VERSION}
CC_VERSION?=		clang
.endif

_COMPILER_ABI_FLAG.32=	-m32
_COMPILER_ABI_FLAG.64=	-m64
_COMPILER_LD_FLAG=	-Wl,
_LINKER_RPATH_FLAG=	-rpath
_COMPILER_RPATH_FLAG=	${_COMPILER_LD_FLAG}${_LINKER_RPATH_FLAG},

# _LANGUAGES.<compiler> is ${LANGUAGES.<compiler>} restricted to the
# ones requested by the package in USE_LANGUAGES.
#
_LANGUAGES.clang=	# empty
.for _lang_ in ${USE_LANGUAGES}
_LANGUAGES.clang+=	${LANGUAGES.clang:M${_lang_}}
.endfor

.endif	# COMPILER_CLANG_MK
