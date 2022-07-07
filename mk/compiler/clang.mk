# $NetBSD: clang.mk,v 1.37 2022/07/07 17:19:55 jperkin Exp $
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

.if exists(${CLANGBASE}/bin/clang-cpp)
CPPPATH=		${CLANGBASE}/bin/clang-cpp
PKG_CPP:=		${CPPPATH}
.endif

.if exists(${CCPATH})
CC_VERSION_STRING!=	${CCPATH} -v 2>&1
CC_VERSION!=		${CCPATH} --version 2>&1 | ${SED} -n "s/^.* version /clang-/p" 
.else
CC_VERSION_STRING?=	${CC_VERSION}
CC_VERSION?=		clang
.endif

_COMPILER_ABI_FLAG.32=	-m32
_COMPILER_ABI_FLAG.64=	-m64
_COMPILER_LD_FLAG=	-Wl,
_LINKER_RPATH_FLAG=	-R
_COMPILER_RPATH_FLAG=	${_COMPILER_LD_FLAG}${_LINKER_RPATH_FLAG}

_CTF_CFLAGS=		-gdwarf-2

# The user or package can choose the level of RELRO.
.if ${PKGSRC_USE_RELRO} != "partial" && \
    ${RELRO_SUPPORTED:Uyes:tl} != "partial"
_RELRO_LDFLAGS=		-Wl,-zrelro -Wl,-znow
.else
_RELRO_LDFLAGS=		-Wl,-zrelro
.endif

# The user can choose the level of stack smashing protection.
.if ${PKGSRC_USE_SSP} == "all"
_SSP_CFLAGS=		-fstack-protector-all
.elif ${PKGSRC_USE_SSP} == "strong"
_SSP_CFLAGS=		-fstack-protector-strong
.else
_SSP_CFLAGS=		-fstack-protector
.endif

.if ${_PKGSRC_USE_RELRO} == "yes"
_CLANG_LDFLAGS+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}
.endif

.if ${_PKGSRC_MKPIE} == "yes"
_MKPIE_CFLAGS.clang=	-fPIC
_MKPIE_LDFLAGS=		-pie

.  if ${PKGSRC_OVERRIDE_MKPIE:tl} == "no"
CFLAGS+=		${_MKPIE_CFLAGS.clang}
CWRAPPERS_APPEND.cc+=	${_MKPIE_CFLAGS.clang}
CWRAPPERS_APPEND.cxx+=	${_MKPIE_CFLAGS.clang}
.  endif
.endif

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

_WRAP_EXTRA_ARGS.CC+=	-Qunused-arguments -fcommon
CWRAPPERS_APPEND.cc+=	-Qunused-arguments
CWRAPPERS_PREPEND.cc+=	-Qunused-arguments -fcommon
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
