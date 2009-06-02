# $NetBSD: ccc.mk,v 1.19 2009/06/02 22:32:49 joerg Exp $
#
# This is the compiler definition for the Compaq C Compilers.
#

.if !defined(COMPILER_CCC_MK)
COMPILER_CCC_MK=	defined

.include "../../mk/bsd.prefs.mk"

# LANGUAGES.<compiler> is the list of supported languages by the
# compiler.
#
LANGUAGES.ccc=		# empty

_CCC_DIR=		${WRKDIR}/.ccc
_CCC_VARS=		# empty
.if exists(/usr/bin/cc)
LANGUAGES.ccc+=		c
_CCC_VARS+=		CC
_CCC_CC=		${_CCC_DIR}/cc
_ALIASES.CC=		cc
CCPATH=			/usr/bin/cc
PKG_CC:=		${_CCC_CC}
.endif
.if exists(/usr/bin/cxx) && exists(/usr/lib/cmplrs/cxx)
LANGUAGES.ccc+=		c++
_CCC_VARS+=		CXX
_CCC_CXX=		${_CCC_DIR}/cxx
_ALIASES.CXX=		c++ cxx
CXXPATH=		/usr/bin/cxx
PKG_CXX:=		${_CCC_CXX}
.endif
_COMPILER_STRIP_VARS+=	${_CCC_VARS}

.if exists(${CCPATH}) && !defined(CC_VERSION_STRING)
CC_VERSION_STRING!=	${CCPATH} -V 2>&1 | ${AWK} '{print; exit(0);}'
CC_VERSION!=		${CCPATH} -V 2>&1 | ${AWK} '{print "CCC-"$3; exit(0);}'
.else
CC_VERSION_STRING?=	${CC_VERSION}
CC_VERSION?=		CCC
.endif

# CCC passes rpath directives to the linker using "-rpath".
_LINKER_RPATH_FLAG=	-rpath

# CCC passes rpath directives to the linker using "-rpath" tailing ",".
_COMPILER_RPATH_FLAG=	-Wl,${_LINKER_RPATH_FLAG},

# Most packages assume ieee floats, make that the default.
CFLAGS+=	-ieee
CXXFLAGS+=	-ieee

# _LANGUAGES.<compiler> is ${LANGUAGES.<compiler>} restricted to the
# ones requested by the package in USE_LANGUAGES.
#
_LANGUAGES.ccc=		# empty
.for _lang_ in ${USE_LANGUAGES}
_LANGUAGES.ccc+=	${LANGUAGES.ccc:M${_lang_}}
.endfor

# Prepend the path to the compiler to the PATH.
.if !empty(_LANGUAGES.ccc)
PREPEND_PATH+=	${_CCC_DIR}/bin
.endif

# Create compiler driver scripts in ${WRKDIR}.
.for _var_ in ${_CCC_VARS}
.  if !target(${_CCC_${_var_}})
override-tools: ${_CCC_${_var_}}
${_CCC_${_var_}}:
	${RUN}${MKDIR} ${.TARGET:H}
.    if !empty(COMPILER_USE_SYMLINKS:M[Yy][Ee][Ss])
	${RUN}${RM} -f ${.TARGET}
	${RUN}${LN} -s /usr/bin/${.TARGET:T} ${.TARGET}
.    else
	${RUN}					\
	(${ECHO} '#!${TOOLS_SHELL}';					\
	 ${ECHO} 'exec /usr/bin/${.TARGET:T} "$$@"';			\
	) > ${.TARGET}
	${RUN}${CHMOD} +x ${.TARGET}
.    endif
.    for _alias_ in ${_ALIASES.${_var_}:S/^/${.TARGET:H}\//}
	${RUN}					\
	if [ ! -x "${_alias_}" ]; then					\
		${LN} -f -s ${.TARGET} ${_alias_};			\
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
