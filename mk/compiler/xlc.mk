# $NetBSD: xlc.mk,v 1.2 2004/10/06 13:56:46 grant Exp $

.if !defined(COMPILER_XLC_MK)
COMPILER_XLC_MK=	defined

.include "../../mk/bsd.prefs.mk"

XLCBASE?=	/opt/ibmcmp/vacpp/6.0

# LANGUAGES.<compiler> is the list of supported languages by the compiler.
# _LANGUAGES.<compiler> is ${LANGUAGES.<compiler>} restricted to the ones
# requested by the package in USE_LANGUAGES.
#
LANGUAGES.xlc=	c c++
_LANGUAGES.xlc=	# empty
.for _lang_ in ${USE_LANGUAGES}
_LANGUAGES.xlc+=	${LANGUAGES.xlc:M${_lang_}}
.endfor

_XLC_DIR=	${WRKDIR}/.xlc
_XLC_LINKS=	# empty
.if exists(${XLCBASE}/bin/xlc)
_XLC_CC=	${_XLC_DIR}/bin/xlc
_XLC_LINKS+=	_XLC_CC
PKG_CC=		${_XLC_CC}
CC=		${PKG_CC:T}
.endif
.if exists(${XLCBASE}/bin/xlc++)
_XLC_CXX=	${_XLC_DIR}/bin/xlc++
_XLC_LINKS+=	_XLC_CXX
PKG_CXX=	${_XLC_CXX}
CXX=		${PKG_CXX:T}
.endif

.if exists(${XLCBASE}/bin/xlc)
CC_VERSION_STRING!=	${XLCBASE}/bin/xlc -V 2>&1 | ${GREP} 'IBM XL C.*for' | ${SED} -e 's/^ *//' || ${TRUE}
CC_VERSION=		${CC_VERSION_STRING}
.else
CC_VERSION_STRING?=	${CC_VERSION}
CC_VERSION?=		IBM XL C
.endif

# Prepend the path to the compiler to the PATH.
.if !empty(_LANGUAGES.xlc)
PREPEND_PATH+=	${_XLC_DIR}/bin
.endif

# Create compiler driver scripts in ${WRKDIR}.
.for _target_ in ${_XLC_LINKS}
.  if !target(${${_target_}})
override-tools: ${${_target_}}        
${${_target_}}:
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	(${ECHO} '#!${TOOLS_SHELL}';					\
	 ${ECHO} 'exec ${XLCBASE}/bin/${${_target_}:T} "$$@"';	\
	) > ${.TARGET}
	${_PKG_SILENT}${_PKG_DEBUG}${CHMOD} +x ${.TARGET}
.  endif
.endfor

.endif	# COMPILER_XLC_MK
