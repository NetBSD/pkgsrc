# $NetBSD: mipspro.mk,v 1.24 2004/06/10 20:34:08 jschauma Exp $

.if !defined(COMPILER_MIPSPRO_MK)
COMPILER_MIPSPRO_MK=	defined

.include "../../mk/bsd.prefs.mk"

MIPSPROBASE?=	/usr

# LANGUAGES.<compiler> is the list of supported languages by the compiler.
# _LANGUAGES.<compiler> is ${LANGUAGES.<compiler>} restricted to the ones
# requested by the package in USE_LANGUAGES.
# 
LANGUAGES.mipspro=	c c++
_LANGUAGES.mipspro=	# empty
.for _lang_ in ${USE_LANGUAGES}
_LANGUAGES.mipspro+=	${LANGUAGES.mipspro:M${_lang_}}
.endfor

_MIPSPRO_DIR=		${WRKDIR}/.mipspro
_MIPSPRO_LINKS=		# empty
.if exists(${MIPSPROBASE}/bin/cc)
_MIPSPRO_CC=		${_MIPSPRO_DIR}/bin/cc
_MIPSPRO_LINKS+=	_MIPSPRO_CC
PKG_CC=			${_MIPSPRO_CC}
CC=			${PKG_CC:T}
.endif
.if exists(${MIPSPROBASE}/bin/CC)
_MIPSPRO_CXX=		${_MIPSPRO_DIR}/bin/CC
_MIPSPRO_LINKS+=	_MIPSPRO_CXX
PKG_CXX=		${_MIPSPRO_CXX}
CXX=			${PKG_CXX:T}
.endif

.if exists(${MIPSPROBASE}/bin/cc)
# MIPSpro Compilers: Version 7.3.1.2m
CC_VERSION_STRING!=	${MIPSPROBASE}/bin/cc -version 2>&1 || ${TRUE}
CC_VERSION!=		${MIPSPROBASE}/bin/cc -version 2>&1 | ${GREP} '^MIPSpro'
.else
CC_VERSION_STRING?=	${CC_VERSION}
CC_VERSION?=		MIPSpro Compilers
.endif

# MIPSPro passes flags to the linker using "-Wl,".
_COMPILER_LD_FLAG=	-Wl,

# Prepend the path to the compiler to the PATH.
.if !empty(_LANGUAGES.mipspro)
PREPEND_PATH+=	${_MIPSPRO_DIR}/bin
.endif

# Create compiler driver scripts in ${WRKDIR}.
.for _target_ in ${_MIPSPRO_LINKS}
.  if !target(${${_target_}})
override-tools: ${${_target_}}
${${_target_}}:
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	(${ECHO} '#!${TOOLS_SHELL}';					\
	 ${ECHO} 'exec ${MIPSPROBASE}/bin/${${_target_}:T} "$$@"';	\
	) > ${.TARGET}
	${_PKG_SILENT}${_PKG_DEBUG}${CHMOD} +x ${.TARGET}
.  endif
.endfor

.if defined(ABI)
MABIFLAG=       -${ABI:C/^32$/n&/}
CFLAGS+=        ${MABIFLAG}
LDFLAGS+=       ${MABIFLAG}
.endif

.endif	# COMPILER_MIPSPRO_MK
