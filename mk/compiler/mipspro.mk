# $NetBSD: mipspro.mk,v 1.5 2004/02/02 10:03:46 jlam Exp $

.if !defined(COMPILER_MIPSPRO_MK)
COMPILER_MIPSPRO_MK=	defined

MIPSPROBASE?=	/usr
PATH:=		${MIPSPROBASE}/bin:${PATH}

# LANGUAGES.<compiler> is the list of supported languages by the compiler.
# _LANGUAGES.<compiler> is ${LANGUAGES.<compiler>} restricted to the ones
# requested by the package in USE_LANGUAGES.
# 
LANGUAGES.mipspro=	c c++
_LANGUAGES.mipspro=	# empty
.for _lang_ in ${USE_LANGUAGES}
_LANGUAGES.mipspro=	${LANGUAGES.mipspro:M${_lang_}}
.endfor

.if !empty(_LANGUAGES.mipspro:Mc)
CC=	${MIPSPROBASE}/bin/cc
CPP=	${MIPSPROBASE}/bin/cc -E
.endif
.if !empty(_LANGUAGES.mipspro:Mc++)
CXX=	${MIPSPROBASE}/bin/CC
.endif

CC_VERSION!=	${CC} -V 2>&1 | ${GREP} '^cc'

.endif	# COMPILER_MIPSPRO_MK
