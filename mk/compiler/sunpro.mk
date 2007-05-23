# $NetBSD: sunpro.mk,v 1.41 2007/05/23 08:42:36 sketch Exp $
#
# This is the compiler definition for the SUNWspro C compiler.
#
# User-settable variables:
#
# SUNWSPROBASE
#	The base directory where the compiler is installed.
#

.if !defined(COMPILER_SUNPRO_MK)
COMPILER_SUNPRO_MK=	defined

.include "../../mk/bsd.prefs.mk"

SUNWSPROBASE?=		/opt/SUNWspro

# common definitions
_COMPILER_TYPE.c=	CC
_COMPILER_TYPE.c++ =	CXX
_COMPILER_TYPE.fortran=	FC

# sunpro-specific definitions
_COMPILER_LANGS=	c c++ fortran
_COMPILER_NAME.c=	cc
_COMPILER_NAME.c++ =	CC
_COMPILER_NAME.fortran=	f77

# LANGUAGES.<compiler> is the list of supported languages by the
# compiler.
#
LANGUAGES.sunpro=	# empty

.for l in ${_COMPILER_LANGS}
.  for t in ${_COMPILER_TYPE.${l}}
.    for n in ${_COMPILER_NAME.${l}}
.      if exists(${SUNWSPROBASE}/bin/${n})
LANGUAGES.sunpro+=	${l}
_COMPILER_STRIP_VARS+=	${t}
${t}PATH=		${SUNWSPROBASE}/bin/${n}
PKG_${t}:=		${SUNWSPROBASE}/bin/${n}
.      endif
.    endfor
.  endfor
.endfor

# Turn on C99 support if required
.if !empty(USE_LANGUAGES:Mc99)
_WRAP_EXTRA_ARGS.CC+=	-xc99
.endif

# The Solaris linker uses "-R" for rpath directives.
_LINKER_RPATH_FLAG=	-R

# SunPro passes rpath directives to the linker using "-R", however
# some packages require the "-Wl," prefix to recognize linker options.
# This is transformed by the compiler wrapper to "-R".
_COMPILER_RPATH_FLAG=	-Wl,-R

# SunPro compiler must be passed certain flags to compile/link 64-bit code.
.if ${MACHINE_ARCH} == "sparc"
_COMPILER_ABI_FLAG.64=	-xtarget=ultra -xarch=v9
.else
_COMPILER_ABI_FLAG.64= -xarch=amd64
.endif

.if exists(${CCPATH})
CC_VERSION_STRING!=	${CCPATH} -V 2>&1 || ${TRUE}
CC_VERSION!=		${CCPATH} -V 2>&1 | ${GREP} '^cc'
.else
CC_VERSION_STRING?=	${CC_VERSION}
CC_VERSION?=		cc: Sun C
.endif

# _LANGUAGES.<compiler> is ${LANGUAGES.<compiler>} restricted to the
# ones requested by the package in USE_LANGUAGES.
#
_LANGUAGES.sunpro=	# empty
.for _lang_ in ${USE_LANGUAGES}
_LANGUAGES.sunpro+=	${LANGUAGES.sunpro:M${_lang_}}
.endfor

.endif	# COMPILER_SUNPRO_MK
