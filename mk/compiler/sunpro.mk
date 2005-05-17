# $NetBSD: sunpro.mk,v 1.32 2005/05/17 19:06:21 rillig Exp $

.if !defined(COMPILER_SUNPRO_MK)
COMPILER_SUNPRO_MK=	defined

.include "../../mk/bsd.prefs.mk"

SUNWSPROBASE?=	/opt/SUNWspro

# LANGUAGES.<compiler> is the list of supported languages by the
# compiler.
#
LANGUAGES.sunpro=	# empty

_SUNPRO_DIR=		${WRKDIR}/.sunpro
_SUNPRO_VARS=		# empty
.if exists(${SUNWSPROBASE}/bin/cc)
LANGUAGES.sunpro+=	c
_SUNPRO_VARS+=		CC
_SUNPRO_CC=		${_SUNPRO_DIR}/bin/cc
_ALIASES.CC=		cc gcc
CCPATH=			${SUNWSPROBASE}/bin/cc
PKG_CC:=		${_SUNPRO_CC}
.endif
.if exists(${SUNWSPROBASE}/bin/CC)
LANGUAGES.sunpro+=	c++
_SUNPRO_VARS+=		CXX
_SUNPRO_CXX=		${_SUNPRO_DIR}/bin/CC
_ALIASES.CXX=		CC c++ g++
CXXPATH=		${SUNWSPROBASE}/bin/CC
PKG_CXX:=		${_SUNPRO_CXX}
.endif
_COMPILER_STRIP_VARS+=	${_SUNPRO_VARS}

# SunPro passes rpath directives to the linker using "-R".
_LINKER_RPATH_FLAG=	-R

# SunPro passes rpath directives to the linker using "-R".
_COMPILER_RPATH_FLAG=	-R

# SunPro compiler must be passed certain flags to compile/link 64-bit code.
_COMPILER_ABI_FLAG.64=	-xtarget=ultra -xarch=v9

.if exists(${CCPATH})
CC_VERSION_STRING!=	${CCPATH} -V 2>&1 || ${TRUE}
CC_VERSION!=		${CCPATH} -V 2>&1 | ${GREP} '^cc'
.else
CC_VERSION_STRING?=	${CC_VERSION}
CC_VERSION?=		cc: Sun C
.endif

# _LANGUAGES.<compiler> is ${LANGUAGES.<compiler>} restricted to the
# ones requested by the package in USE_LANGUAGES.
#
_LANGUAGES.sunpro=	# empty
.for _lang_ in ${USE_LANGUAGES}
_LANGUAGES.sunpro+=	${LANGUAGES.sunpro:M${_lang_}}
.endfor

# Prepend the path to the compiler to the PATH.
.if !empty(_LANGUAGES.sunpro)
PREPEND_PATH+=	${_SUNPRO_DIR}/bin
.endif

# Create compiler driver scripts in ${WRKDIR}.
.for _var_ in ${_SUNPRO_VARS}
.  if !target(${_SUNPRO_${_var_}})
override-tools: ${_SUNPRO_${_var_}}        
${_SUNPRO_${_var_}}:
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	(${ECHO} '#!${TOOLS_SHELL}';					\
	 ${ECHO} 'exec ${SUNWSPROBASE}/bin/${.TARGET:T} "$$@"';		\
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
_SUNPRO_USE_F2C=	no
FCPATH=			/nonexistent
.if !exists(${FCPATH})
_SUNPRO_USE_F2C=	yes
.endif
.if !empty(_SUNPRO_USE_F2C:M[yY][eE][sS])
.  include "../../mk/compiler/f2c.mk"
.endif

.endif	# COMPILER_SUNPRO_MK
