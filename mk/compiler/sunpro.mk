# $NetBSD: sunpro.mk,v 1.8 2004/02/05 03:39:17 jlam Exp $

.if !defined(COMPILER_SUNPRO_MK)
COMPILER_SUNPRO_MK=	one

SUNWSPROBASE?=	/opt/SUNWspro

# LANGUAGES.<compiler> is the list of supported languages by the compiler.
# _LANGUAGES.<compiler> is ${LANGUAGES.<compiler>} restricted to the ones
# requested by the package in USE_LANGUAGES.
#
LANGUAGES.sunpro=	c c++
_LANGUAGES.sunpro=	# empty
.  for _lang_ in ${USE_LANGUAGES}
_LANGUAGES.sunpro+=	${LANGUAGES.sunpro:M${_lang_}}
.  endfor

.  if !empty(_LANGUAGES.sunpro:Mc)
CC=	${SUNWSPROBASE}/bin/cc
CPP=	${SUNWSPROBASE}/bin/cc -E
.  endif
.  if !empty(_LANGUAGES.sunpro:Mc++)
CXX=	${SUNWSPROBASE}/bin/CC
.  endif

_COMPILER_LD_FLAG=	# empty

.  if exists(${CC})
CC_VERSION!=	${CC} -V 2>&1 | ${GREP} '^cc'
.  else
CC_VERSION=	sunpro
.  endif
.endif	# COMPILER_SUNPRO_MK

# The following section is included only if we're not being included by
# bsd.prefs.mk.
#
.if empty(BSD_PREFS_MK)
.  if empty(COMPILER_SUNPRO_MK:Mtwo)
COMPILER_SUNPRO_MK+=	two

# Prepend the path to the compiler to the PATH.
.    if !empty(_LANGUAGES.sunpro)
PATH:=	${SUNWSPROBASE}/bin:${PATH}
.    endif
.  endif # COMPILER_SUNPRO_MK
.endif	 # BSD_PREFS_MK
