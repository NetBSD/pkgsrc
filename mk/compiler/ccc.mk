# $NetBSD: ccc.mk,v 1.10 2005/01/12 17:39:34 jlam Exp $

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
_CCC_VARS=	# empty
.if exists(/usr/bin/cc)
_CCC_VARS+=	CC
_CCC_CC=	${_CCC_DIR}/cc
_ALIASES.CC=	cc
CCPATH=		/usr/bin/cc
PKG_CC:=	${_CCC_CC}
.endif
.if exists(/usr/bin/cxx)
_CCC_VARS+=	CXX
_CCC_CXX=	${_CCC_DIR}/cxx
_ALIASES.CXX=	c++ cxx
CXXPATH=	/usr/bin/cxx
PKG_CXX:=	${_CCC_CXX}
.endif
_COMPILER_STRIP_VARS+=	${_CCC_VARS}

.if exists(${CCPATH}) && !defined(CC_VERSION_STRING)
CC_VERSION_STRING!=	${CCPATH} -V 2>&1 | awk '{print; exit(0);}'
CC_VERSION!=		${CCPATH} -V 2>&1 | awk '{print "CCC-"$3; exit(0);}'
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
CFLAGS+=	-ieee
CXXFLAGS+=	-ieee

# Prepend the path to the compiler to the PATH.
.if !empty(_LANGUAGES.ccc)
PREPEND_PATH+=	${_CCC_DIR}/bin
.endif

# Create compiler driver scripts in ${WRKDIR}.
.for _var_ in ${_CCC_VARS}
.  if !target(${_CCC_${_var_}})
override-tools: ${_CCC_${_var_}}        
${_CCC_${_var_}}:
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	(${ECHO} '#!${TOOLS_SHELL}';					\
	 ${ECHO} 'exec /usr/bin/${.TARGET:T} "$$@"';			\
	) > ${.TARGET}
	${_PKG_SILENT}${_PKG_DEBUG}${CHMOD} +x ${.TARGET}
.    for _alias_ in ${_ALIASES.${_var_}:S/^/${.TARGET:H}\//}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	if [ ! -x "${_alias_}" ]; then					\
		${LN} -f ${.TARGET} ${_alias_};				\
	fi
.    endfor
.  endif
.endfor

# Force the use of f2c-f77 for compiling Fortran.
_CCC_USE_F2C=	no
FCPATH=		/nonexistent
.if !exists(${FCPATH})
_CCC_USE_F2C=	yes
.endif
.if !empty(_CCC_USE_F2C:M[yY][eE][sS])
.  include "../../mk/compiler/f2c.mk"
.endif

.endif	# COMPILER_CCC_MK
