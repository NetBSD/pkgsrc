# $NetBSD: sunpro.mk,v 1.3 2004/02/02 10:03:46 jlam Exp $

.if !defined(COMPILER_SUNPRO_MK)
COMPILER_SUNPRO_MK=	defined

SUNWSPROBASE?=	/opt/SUNWspro
PATH:=		${SUNWSPROBASE}/bin:${PATH}

# LANGUAGES.<compiler> is the list of supported languages by the compiler.
# _LANGUAGES.<compiler> is ${LANGUAGES.<compiler>} restricted to the ones
# requested by the package in USE_LANGUAGES.
#
LANGUAGES.sunpro=	c c++
_LANGUAGES.sunpro=	# empty
.for _lang_ in ${USE_LANGUAGES}
_LANGUAGES.sunpro=	${LANGUAGES.sunpro:M${_lang_}}
.endfor

.if !empty(_LANGUAGES.sunpro:Mc)
CC=	${SUNWSPROBASE}/bin/cc
CPP=	${SUNWSPROBASE}/bin/cc -E
.endif
.if !empty(_LANGUAGES.sunpro:Mc++)
CXX=	${SUNWSPROBASE}/bin/CC
.endif

_COMPILER_LD_FLAG=	# empty

CC_VERSION!=	${CC} -V 2>&1 | ${GREP} '^cc'

.endif	# COMPILER_SUNPRO_MK
