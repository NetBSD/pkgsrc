# $NetBSD: sunpro.mk,v 1.11 2004/02/07 02:58:10 jlam Exp $

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

_SUNPRO_DIR=	${WRKDIR}/.sunpro
_SUNPRO_LINKS=	# empty
.  if !empty(_LANGUAGES.sunpro:Mc)
_SUNPRO_CC=	${_SUNPRO_DIR}/bin/cc
_SUNPRO_LINKS+=	_SUNPRO_CC
CC=		${_SUNPRO_CC}
CPP=		${_SUNPRO_CC} -E
.  endif
.  if !empty(_LANGUAGES.sunpro:Mc++)
_SUNPRO_CXX=	${_SUNPRO_DIR}/bin/CC
_SUNPRO_LINKS+=	_SUNPRO_CXX
CXX=		${_SUNPRO_CXX}
.  endif

_COMPILER_LD_FLAG=	# empty

.  if exists(${SUNWSPROBASE}/bin/cc)
CC_VERSION!=	${SUNWSPROBASE}/bin/cc -V 2>&1 | ${GREP} '^cc'
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
.      if empty(PREPEND_PATH:M${_SUNPRO_DIR}/bin)
PREPEND_PATH+=	${_SUNPRO_DIR}/bin
PATH:=		${_SUNPRO_DIR}/bin:${PATH}
.      endif
.    endif

# Create symlinks for the compiler into ${WRKDIR}.
.    for _target_ in ${_SUNPRO_LINKS}
.      if !target(${${_target_}})
override-tools: ${${_target_}}        
${${_target_}}:
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${LN} -fs ${SUNWSPROBASE}/bin/${${_target_}:T} ${.TARGET}
.      endif
.    endfor
.  endif # COMPILER_SUNPRO_MK
.endif	 # BSD_PREFS_MK
