# $NetBSD: mipspro.mk,v 1.16 2004/02/09 05:50:03 jlam Exp $

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

_MIPSPRO_DIR=		${WRKDIR}/.mipspro
_MIPSPRO_LINKS=		# empty
.  if !empty(_LANGUAGES.mipspro:Mc)
_MIPSPRO_CC=		${_MIPSPRO_DIR}/bin/cc
_MIPSPRO_LINKS+=	_MIPSPRO_CC
PKG_CC=			${_MIPSPRO_CC}
PKG_CPP=		${_MIPSPRO_CC} -E
CC=			${PKG_CC:T}
CPP=			${PKG_CPP:T}
.  endif
.  if !empty(_LANGUAGES.mipspro:Mc++)
_MIPSPRO_CXX=		${_MIPSPRO_DIR}/bin/CC
_MIPSPRO_LINKS+=	_MIPSPRO_CXX
PKG_CXX=		${_MIPSPRO_CXX}
CXX=			${PKG_CXX:T}
.  endif

.  if exists(${MIPSPROBASE}/bin/cc)
# MIPSpro Compilers: Version 7.3.1.2m
CC_VERSION!=	${MIPSPROBASE}/bin/cc -version 2>&1 | ${GREP} '^MIPSpro'
.  else
CC_VERSION=	MIPSpro
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
.      if empty(PREPEND_PATH:M${_MIPSPRO_DIR}/bin)
PREPEND_PATH+=	${_MIPSPRO_DIR}/bin
PATH:=		${_MIPSPRO_DIR}/bin:${PATH}
.      endif
.    endif

# Create compiler driver scripts in ${WRKDIR}.
.    for _target_ in ${_MIPSPRO_LINKS}
.      if !target(${${_target_}})
override-tools: ${${_target_}}
${${_target_}}:
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	(${ECHO} '#!${TOOLS_SHELL}';					\
	 ${ECHO} 'exec ${MIPSPROBASE}/bin/${${_target_}:T} "$$@"';	\
	) > ${.TARGET}
	${_PKG_SILENT}${_PKG_DEBUG}${CHMOD} +x ${.TARGET}
.      endif
.    endfor
.  endif # COMPILER_MIPSPRO_MK
.endif	 # BSD_PREFS_MK
