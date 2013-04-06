# $NetBSD: sunpro.mk,v 1.48 2013/04/06 18:09:43 tez Exp $
#
# This is the compiler definition for the SUNWspro C compiler.
#
# User-settable variables:
#
# SUNWSPROBASE
#	The base directory where the compiler is installed.
#
# Keywords: sun sunpro sunwspro
#

.if !defined(COMPILER_SUNPRO_MK)
COMPILER_SUNPRO_MK=	defined

.include "../../mk/bsd.prefs.mk"

SUNWSPROBASE?=		/opt/SUNWspro
.if !exists($SUNWSPROBASE)
SUNWSPROBASE!=         /bin/ls -d /opt/solstudio*
.endif

# common definitions
# XXX: should be moved to compiler.mk.
_COMPILER_TYPE.c=	CC
_COMPILER_TYPE.c++ =	CXX
_COMPILER_TYPE.fortran=	FC

# sunpro-specific definitions
_COMPILER_LANGS=	c c++ fortran fortran77
_COMPILER_NAME.c=	cc
_COMPILER_NAME.c++ =	CC
_COMPILER_NAME.fortran=	f77
_COMPILER_NAME.fortran77=	f77

# LANGUAGES.<compiler> is the list of supported languages by the
# compiler.
#
LANGUAGES.sunpro=	# empty

# XXX: Should be moved to compiler.mk.
.for l in ${_COMPILER_LANGS}
.  for t in ${_COMPILER_TYPE.${l}}
.    for n in ${_COMPILER_NAME.${l}}
.      if exists(${SUNWSPROBASE}/bin/${n})
LANGUAGES.sunpro+=	${l}
_COMPILER_STRIP_VARS+=	${t}
# XXX: What is the ${t}PATH variable used for? And why isn't it
# parameterized as usual? This makes searching for it very difficult.
# Same for PKG_${t}.
${t}PATH=		${SUNWSPROBASE}/bin/${n}
PKG_${t}:=		${SUNWSPROBASE}/bin/${n}
.      endif
.    endfor
.  endfor
.endfor

# Turn on C99 support if required
# XXX: What if a package needs both -- a c89 and a c99 compiler?
#
# Solaris SunPro Compiler 11/12 fails on Solaris 8/9 with -xc99
# The header files supplied by the OS are not c99 aware, the
# manpage suggests the setting: -xc99=all,no_lib
# See PR 37200
.if !empty(USE_LANGUAGES:Mc99)
_WRAP_EXTRA_ARGS.CC+=	-xc99
. if !empty(MACHINE_PLATFORM:MSunOS-5.[89]-*)
_WRAP_EXTRA_ARGS.CC+=   -xc99=all,no_lib
. endif
.endif

# The Solaris linker uses "-R" for rpath directives.
# XXX: This shouldn't be here, but in platform/SunOS.mk.
_LINKER_RPATH_FLAG=	-R

# SunPro passes rpath directives to the linker using "-R", however
# some packages require the "-Wl," prefix to recognize linker options.
# This is transformed by the compiler wrapper to "-R".
_COMPILER_RPATH_FLAG=	-Wl,-R

# XXX: What about the versions of the other compilers? Fortran and C++?
# XXX: should be moved to compiler.mk.
.if exists(${CCPATH})
CC_VERSION_STRING!=	${CCPATH} -V 2>&1 || ${TRUE}
CC_VERSION!=		${CCPATH} -V 2>&1 | ${GREP} '^cc'
.else
CC_VERSION_STRING?=	${CC_VERSION}
CC_VERSION?=		cc: Sun C
.endif

# SunPro compiler must be passed certain flags to compile/link 64-bit code.
.if !empty(CC_VERSION:M5.9) || !empty(CC_VERSION:M5.1[0-9])
_COMPILER_ABI_FLAG.64= -m64
.elif ${MACHINE_ARCH} == "sparc"
_COMPILER_ABI_FLAG.64=	-xtarget=ultra -xarch=v9
.else
_COMPILER_ABI_FLAG.64= -xarch=amd64
.endif

# _LANGUAGES.<compiler> is ${LANGUAGES.<compiler>} restricted to the
# ones requested by the package in USE_LANGUAGES.
#
# XXX: should be moved to compiler.mk.
_LANGUAGES.sunpro=	# empty
.for _lang_ in ${USE_LANGUAGES}
_LANGUAGES.sunpro+=	${LANGUAGES.sunpro:M${_lang_}}
.endfor

.endif	# COMPILER_SUNPRO_MK
