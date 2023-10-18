# $NetBSD: clang.mk,v 1.42 2023/10/18 08:48:51 jperkin Exp $
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
#TOOL_DEPENDS+= clang-[0-9]*:../../lang/clang

.include "../../mk/bsd.prefs.mk"

CLANGBASE?=		${TOOLBASE}
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

.if exists(${CLANGBASE}/bin/clang-cpp)
CPPPATH=		${CLANGBASE}/bin/clang-cpp
PKG_CPP:=		${CPPPATH}
.endif

.if !defined(CC_VERSION)
.  if exists(${CCPATH})
CLANG_VERSION!=		${CCPATH} -dumpversion 2>&1 || ${ECHO} 0
.  else
CLANG_VERSION=		0
.  endif
CC_VERSION=		clang-${CLANG_VERSION}
.endif

#
# TODO: CC_VERSION_STRING is obsolete and should be removed at some point.
#
CC_VERSION_STRING=	${CC_VERSION}

_COMPILER_ABI_FLAG.32=	-m32
_COMPILER_ABI_FLAG.64=	-m64

.include "gcc-style-args.mk"

LDFLAGS+=	${_CLANG_LDFLAGS}

# _LANGUAGES.<compiler> is ${LANGUAGES.<compiler>} restricted to the
# ones requested by the package in USE_LANGUAGES.
#
_LANGUAGES.clang=	# empty
.for _lang_ in ${USE_LANGUAGES}
_LANGUAGES.clang+=	${LANGUAGES.clang:M${_lang_}}
.endfor

PKGSRC_FORTRAN?=gfortran

.if !empty(PKGSRC_FORTRAN) && (!empty(USE_LANGUAGES:Mfortran) || !empty(USE_LANGUAGES:Mfortran77))
.  include "../../mk/compiler/${PKGSRC_FORTRAN}.mk"
.endif

_WRAP_EXTRA_ARGS.CC+=	-Qunused-arguments
CWRAPPERS_APPEND.cc+=	-Qunused-arguments
CWRAPPERS_PREPEND.cc+=	-Qunused-arguments
_WRAP_EXTRA_ARGS.CXX+=	-Qunused-arguments
CWRAPPERS_APPEND.cxx+=	-Qunused-arguments

# Xcode 12 has a zealous new default. Turn it off until we're ready,
# while allowing callers (or users, via CFLAGS/CPPFLAGS) to override.
.if ${OPSYS} == "Darwin"
_NOERROR_IMPLICIT_cmd=	${CCPATH} -\#\#\# -E -x c /dev/null 2>&1 \
			| ${GREP} -q Werror=implicit-function-declaration \
			&& ${ECHO} -Wno-error=implicit-function-declaration \
			|| ${TRUE}
CWRAPPERS_PREPEND.cc+=	${_NOERROR_IMPLICIT_cmd:sh}
.endif

.for _version_ in ${_CXX_STD_VERSIONS}
_CXX_STD_FLAG.${_version_}?=	-std=${_version_}
.endfor

.endif	# COMPILER_CLANG_MK
