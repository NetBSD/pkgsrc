# $NetBSD: ccc.mk,v 1.4 2004/11/23 05:24:28 jlam Exp $

.if !defined(COMPILER_CCC_MK)
COMPILER_CCC_MK=	defined

.include "../../mk/bsd.prefs.mk"

# LANGUAGES.<compiler> is the list of supported languages by the compiler.
# _LANGUAGES.<compiler> is ${LANGUAGES.<compiler>} restricted to the ones
# requested by the package in USE_LANGUAGES.
# 

LANGUAGES.ccc=		c
.if exists(/usr/lib/cmplrs/cxx)
LANGUAGES.ccc+=		c++
.endif
_LANGUAGES.ccc=		# empty
.for _lang_ in ${USE_LANGUAGES}
_LANGUAGES.ccc+=	${LANGUAGES.ccc:M${_lang_}}
.endfor

_CCC_DIR=	${WRKDIR}/.ccc
_CCC_LINKS=	# empty
.if exists(/usr/bin/cc)
_CCC_CC=	${_CCC_DIR}/cc
_CCC_LINKS+=	_CCC_CC
PKG_CC=		${_CCC_CC}
CC=		${PKG_CC:T}
CCPATH=		/usr/bin/cc
.endif

.if exists(/usr/bin/cxx)
_CCC_CXX=	${_CCC_DIR}/cxx
_CCC_LINKS+=	_CCC_CXX
PKG_CXX=	${_CCC_CXX}
CXX=		${PKG_CXX:T}
CXXPATH=	/usr/bin/cxx
.endif

.if exists(/usr/bin/cc) && !defined(CC_VERSION_STRING)
CC_VERSION_STRING!=	/usr/bin/cc -V 2>&1 | awk '{print; exit(0);}'
CC_VERSION!=		/usr/bin/cc -V 2>&1 | awk '{print "CCC-"$3; exit(0);}'
.else
CC_VERSION_STRING?=	${CC_VERSION}
CC_VERSION?=		CCC
.endif

# CCC passes flags to the linker using "-Wl,".
_COMPILER_LD_FLAG=	-Wl,

# CCC passes rpath directives to the linker using "-rpath".
_LINKER_RPATH_FLAG=	-rpath

# CCC passes rpath directives to the linker using "-rpath" tailing ",".
_COMPILER_RPATH_FLAG=	${_COMPILER_LD_FLAG}${_LINKER_RPATH_FLAG},

# Most packages assume ieee floats, make that the default.
CFLAGS+=-ieee
CXXFLAGS+=-ieee

# Create compiler driver scripts in ${WRKDIR}.
.for _target_ in ${_CCC_LINKS}
.  if !target(${${_target_}})
override-tools: ${${_target_}}
${${_target_}}:
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	(${ECHO} '#!${TOOLS_SHELL}';					\
	 ${ECHO} 'exec /usr/bin/${${_target_}:T} "$$@"';	\
	) > ${.TARGET}
	${_PKG_SILENT}${_PKG_DEBUG}${CHMOD} +x ${.TARGET}
.  endif
.endfor

.endif	# COMPILER_CCC_MK
