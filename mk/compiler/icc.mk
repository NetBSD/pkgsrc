# $NetBSD: icc.mk,v 1.5 2008/02/07 20:59:05 rillig Exp $
#
# This is the compiler definition for the Intel compilers.
#
# User-settable variables:
#
# ICCBASE
#	The base directory where the compiler is installed.
#

.if !defined(COMPILER_ICC_MK)
COMPILER_ICC_MK=	defined

.include "../../mk/bsd.prefs.mk"

ICCBASE?=		/opt/intel_cc_80

# LANGUAGES.<compiler> is the list of supported languages by the
# compiler.
#
LANGUAGES.icc=		# empty

_ICC_DIR=		${WRKDIR}/.icc
_ICC_VARS=		# empty
.if exists(${ICCBASE}/bin/icc)
LANGUAGES.icc+=		c
_ICC_VARS+=		CC
_ICC_CC=		${_ICC_DIR}/bin/icc
_ALIASES.CC=		cc
CCPATH=			${ICCBASE}/bin/icc
PKG_CC:=		${_ICC_CC}
LANGUAGES.icc+=		c++
_ICC_VARS+=		CXX
_ICC_CXX=		${_ICC_DIR}/bin/icpc
_ALIASES.CXX=		CC c++
CXXPATH=		${ICCBASE}/bin/icpc
PKG_CXX:=		${_ICC_CXX}
.endif
_COMPILER_STRIP_VARS+=	${_ICC_VARS}

# icc passes rpath directives to the linker using "-Wl,-R".
_LINKER_RPATH_FLAG=	-Wl,-R

# icc passes rpath directives to the linker using "-Wl,-R".
_COMPILER_RPATH_FLAG=	-Wl,-R

.if exists(${CCPATH})
CC_VERSION_STRING!=	${CCPATH} -V 2>&1 | ${GREP} '^Intel'
_CC_VERSION!=		${CCPATH} -v 2>&1 || ${TRUE}
CC_VERSION=		Intel C++ Compiler ${_CC_VERSION}
.else
CC_VERSION_STRING?=	${CC_VERSION}
CC_VERSION?=		Intel C++ Compiler
.endif

# _LANGUAGES.<compiler> is ${LANGUAGES.<compiler>} restricted to the
# ones requested by the package in USE_LANGUAGES.
#
_LANGUAGES.icc=	# empty
.for _lang_ in ${USE_LANGUAGES}
_LANGUAGES.icc+=	${LANGUAGES.icc:M${_lang_}}
.endfor

# Prepend the path to the compiler to the PATH.
.if !empty(_LANGUAGES.icc)
PREPEND_PATH+=	${_ICC_DIR}/bin
.endif

# icc supports __attribute__, but the GNU configure test uses a nested
# function, which icc does not support. #undef'ing __attribute__ has the
# unfortunate side-effect of breaking many of the Linux header files, which
# cannot be compiled properly without __attribute__. The test must be
# overridden so that __attribute__ is assumed supported by the compiler.
.if defined(GNU_CONFIGURE)
CONFIGURE_ENV+=		ac_cv___attribute__=yes
.endif

# Create compiler driver scripts in ${WRKDIR}.
.for _var_ in ${_ICC_VARS}
.  if !target(${_ICC_${_var_}})
override-tools: ${_ICC_${_var_}}
${_ICC_${_var_}}:
	${RUN}${MKDIR} ${.TARGET:H}
	${RUN}					\
	(${ECHO} '#!${TOOLS_SHELL}';					\
	 ${ECHO} 'exec ${ICCBASE}/bin/${.TARGET:T} "$$@"';		\
	) > ${.TARGET}
	${RUN}${CHMOD} +x ${.TARGET}
.    for _alias_ in ${_ALIASES.${_var_}:S/^/${.TARGET:H}\//}
	${RUN}					\
	if [ ! -x "${_alias_}" ]; then					\
		${LN} -f ${.TARGET} ${_alias_};				\
	fi
.    endfor
.  endif
.endfor

.endif	# COMPILER_ICC_MK
