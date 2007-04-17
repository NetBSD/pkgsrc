# $NetBSD: hp.mk,v 1.2 2007/04/17 11:09:28 tnn Exp $
#
# This is the compiler definition for the HP-UX C/aC++ compilers.
#

.if !defined(COMPILER_HP_MK)
COMPILER_HP_MK=		defined

.include "../../mk/bsd.prefs.mk"

# LANGUAGES.<compiler> is the list of supported languages by the
# compiler.
#
LANGUAGES.hp=		# empty

_HP_DIR=		${WRKDIR}/.hp
_HP_VARS=		# empty
.if exists(/usr/bin/cc)
LANGUAGES.hp+=		c
_HP_VARS+=		CC
_HP_CC=			${_HP_DIR}/cc
_ALIASES.CC=		cc
CCPATH=			/usr/bin/cc
PKG_CC:=		${_HP_CC}
.endif
.if exists(/opt/aCC/bin/aCC)
LANGUAGES.hp+=		c++
_HP_VARS+=		CXX
_HP_CXX=		${_HP_DIR}/aCC
_ALIASES.CXX=		c++
CXXPATH=		/opt/aCC/bin/aCC
PKG_CXX:=		${_HP_CXX}
.endif
_COMPILER_STRIP_VARS+=	${_HP_VARS}

.if exists(${CXXPATH}) && !defined(CC_VERSION_STRING)
CC_VERSION_STRING!=	${CXXPATH} -V 2>&1
CC_VERSION=		${CC_VERSION_STRING:S/ /_/Wg}
.else
CC_VERSION_STRING?=	${CC_VERSION}
CC_VERSION?=		hp
.endif

# HP comilers pass flags to the linker using "-Wl,".
_COMPILER_LD_FLAG=	-Wl,

# linker syntax for rpath is +b /path1:/path2:...
_LINKER_RPATH_FLAG=	+b

# HP compilers pass rpath directives to the linker using "-Wl,+b,"
_COMPILER_RPATH_FLAG=	${_COMPILER_LD_FLAG}${_LINKER_RPATH_FLAG},

# _LANGUAGES.<compiler> is ${LANGUAGES.<compiler>} restricted to the
# ones requested by the package in USE_LANGUAGES.
# 
_LANGUAGES.hp=		# empty
.for _lang_ in ${USE_LANGUAGES}
_LANGUAGES.hp+=	${LANGUAGES.hp:M${_lang_}}
.endfor

# Prepend the path to the compiler to the PATH.
.if !empty(_LANGUAGES.hp)
PREPEND_PATH+=	${_HP_DIR}/bin
.endif

# Create compiler driver scripts in ${WRKDIR}.
.for _var_ in ${_HP_VARS}
.  if !target(${_HP_${_var_}})
override-tools: ${_HP_${_var_}}        
${_HP_${_var_}}:
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	(${ECHO} '#!${TOOLS_SHELL}';					\
	 ${ECHO} 'exec ${${_var_}PATH} "$$@"';			\
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

_COMPILER_ABI_FLAG.32=+DD32
_COMPILER_ABI_FLAG.64=+DD64

.endif	# COMPILER_HP_MK
