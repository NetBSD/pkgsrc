# $NetBSD: sunpro.mk,v 1.13 2004/02/09 05:50:03 jlam Exp $

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
PKG_CC=		${_SUNPRO_CC}
PKG_CPP=	${_SUNPRO_CC} -E
CC=		${PKG_CC:T}
CPP=		${PKG_CPP:T}
.  endif
.  if !empty(_LANGUAGES.sunpro:Mc++)
_SUNPRO_CXX=	${_SUNPRO_DIR}/bin/CC
_SUNPRO_LINKS+=	_SUNPRO_CXX
PKG_CXX=	${_SUNPRO_CXX}
CXX=		${PKG_CXX:T}
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

# Create compiler driver scripts in ${WRKDIR}.
.    for _target_ in ${_SUNPRO_LINKS}
.      if !target(${${_target_}})
override-tools: ${${_target_}}        
${${_target_}}:
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	(${ECHO} '#!${TOOLS_SHELL}';					\
	 ${ECHO} 'exec ${SUNWSPROBASE}/bin/${${_target_}:T} "$$@"';	\
	) > ${.TARGET}
	${_PKG_SILENT}${_PKG_DEBUG}${CHMOD} +x ${.TARGET}
.      endif
.    endfor
.  endif # COMPILER_SUNPRO_MK
.endif	 # BSD_PREFS_MK
