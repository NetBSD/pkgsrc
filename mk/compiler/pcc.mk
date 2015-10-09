# $NetBSD: pcc.mk,v 1.8 2015/10/09 17:27:09 he Exp $
#
# This is the compiler definition for the PCC compiler.
#
# User-settable variables:
#
# PCCBASE
#	The base directory where the compiler is installed.
#

.if !defined(COMPILER_PCC_MK)
COMPILER_PCC_MK=	defined

# Add the dependency on pcc
# NOTE: not enabled by default as may be installed already
# TODO: check for this?
#TOOL_DEPENDS+= pcc-[0-9]*:../../lang/pcc

.include "../../mk/bsd.prefs.mk"

PCCBASE?=		${LOCALBASE}

# common definitions
_COMPILER_TYPE.c=	CC
_COMPILER_TYPE.c++ =	CXX
_COMPILER_TYPE.fortran=	FC

# PCC-specific definitions
_COMPILER_LANGS=	c c++ fortran77
_COMPILER_NAME.c=	pcc
# TODO:
_COMPILER_NAME.c++ =	CC
_COMPILER_NAME.fortran77=	f77

# LANGUAGES.<compiler> is the list of supported languages by the
# compiler.
#
LANGUAGES.pcc=	# empty

.for l in ${_COMPILER_LANGS}
.  for t in ${_COMPILER_TYPE.${l}}
.    for n in ${_COMPILER_NAME.${l}}
.      if exists(${PCCBASE}/bin/${n})
LANGUAGES.pcc+=	${l}
_COMPILER_STRIP_VARS+=	${t}
${t}PATH=		${PCCBASE}/bin/${n}
PKG_${t}:=		${PCCBASE}/bin/${n}
.      endif
.    endfor
.  endfor
.endfor

# Turn on C99 support if required
#.if !empty(USE_LANGUAGES:Mc99)
#_WRAP_EXTRA_ARGS.CC+=	-xc99
#.endif

_LINKER_RPATH_FLAG=	-R

_COMPILER_RPATH_FLAG=	-Wl,-R

.if exists(${CCPATH})
CC_VERSION_STRING!=	${CCPATH} -v 2>&1 || ${TRUE}
CC_VERSION!=		${CCPATH} -v 2>&1 | ${GREP} -E '^(pcc|Portable C Compiler)'
.else
CC_VERSION_STRING?=	${CC_VERSION}
CC_VERSION?=		pcc
.endif

# _LANGUAGES.<compiler> is ${LANGUAGES.<compiler>} restricted to the
# ones requested by the package in USE_LANGUAGES.
#
_LANGUAGES.pcc=	# empty
.for _lang_ in ${USE_LANGUAGES}
_LANGUAGES.pcc+=	${LANGUAGES.pcc:M${_lang_}}
.endfor

.endif	# COMPILER_PCC_MK
