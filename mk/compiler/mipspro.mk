# $NetBSD: mipspro.mk,v 1.10 2004/02/05 03:39:17 jlam Exp $

.if !defined(COMPILER_MIPSPRO_MK)
COMPILER_MIPSPRO_MK=	one

MIPSPROBASE?=	/usr

# LANGUAGES.<compiler> is the list of supported languages by the compiler.
# _LANGUAGES.<compiler> is ${LANGUAGES.<compiler>} restricted to the ones
# requested by the package in USE_LANGUAGES.
# 
LANGUAGES.mipspro=	c c++
_LANGUAGES.mipspro=	# empty
.  for _lang_ in ${USE_LANGUAGES}
_LANGUAGES.mipspro+=	${LANGUAGES.mipspro:M${_lang_}}
.  endfor

.  if !empty(_LANGUAGES.mipspro:Mc)
CC=	${MIPSPROBASE}/bin/cc
CPP=	${MIPSPROBASE}/bin/cc -E
.  endif
.  if !empty(_LANGUAGES.mipspro:Mc++)
CXX=	${MIPSPROBASE}/bin/CC
.  endif

.  if exists(${CC})
CC_VERSION!=	${CC} -V 2>&1 | ${GREP} '^cc'
.  else
CC_VERSION=	mipspro
.  endif
.endif	# COMPILER_MIPSPRO_MK

# The following section is included only if we're not being included by
# bsd.prefs.mk.
#
.if empty(BSD_PREFS_MK)
.  if empty(COMPILER_MIPSPRO_MK:Mtwo)
COMPILER_MIPSPRO_MK+=	two

# Prepend the path to the compiler to the PATH.
.    if !empty(_LANGUAGES.mipspro)
PATH:=	${MIPSPROBASE}/bin:${PATH}
.    endif
.  endif # COMPILER_MIPSPRO_MK
.endif	 # BSD_PREFS_MK
