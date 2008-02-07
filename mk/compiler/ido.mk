# $NetBSD: ido.mk,v 1.6 2008/02/07 20:59:05 rillig Exp $
#
# This is the compiler definition for the SGI IRIS Development Option
# cc (IRIX 5).
#
# User-settable variables:
#
# IDOBASE
#	The base directory where the compiler is installed.
#

.if !defined(COMPILER_IDO_MK)
COMPILER_IDO_MK=	defined

.include "../../mk/bsd.prefs.mk"

IDOBASE?=	/usr

# LANGUAGES.<compiler> is the list of supported languages by the
# compiler.
#
LANGUAGES.ido=		# empty

_IDO_DIR=		${WRKDIR}/.ido
_IDO_VARS=		# empty
.if exists(${IDOBASE}/bin/cc)
LANGUAGES.ido+=		c
_IDO_VARS+=		CC
_IDO_CC=		${_IDO_DIR}/bin/cc
_ALIASES.CC=		cc
CCPATH=			${IDOBASE}/bin/cc
PKG_CC:=		${_IDO_CC}
.endif
.if exists(${IDOBASE}/lib/cpp)
_IDO_VARS+=		CPP
_IDO_CPP=		${_IDO_DIR}/bin/cpp
_ALIASES.CPP=		cpp
CPPPATH=		${IDOBASE}/lib/cpp
PKG_CPP:=		${_IDO_CPP}
.endif
_COMPILER_STRIP_VARS+=	${_IDO_VARS}

CC_VERSION?=		${LOWER_OPSYS} ido cc

# IDO linker option used to set the rpath.
_LINKER_RPATH_FLAG=	-rpath

# IDO passes rpath directives to the linker using "-Wl,-rpath,".
_COMPILER_RPATH_FLAG=	-Wl,${_LINKER_RPATH_FLAG},

# _LANGUAGES.<compiler> is ${LANGUAGES.<compiler>} restricted to the
# ones requested by the package in USE_LANGUAGES.
#
_LANGUAGES.ido=		# empty
.for _lang_ in ${USE_LANGUAGES}
_LANGUAGES.ido+=	${LANGUAGES.ido:M${_lang_}}
.endfor

# Prepend the path to the compiler to the PATH.
.if !empty(_LANGUAGES.ido)
PREPEND_PATH+=	${_IDO_DIR}/bin
.endif

# Create compiler driver scripts in ${WRKDIR}.
.for _var_ in ${_IDO_VARS}
.  if !target(${_IDO_${_var_}})
override-tools: ${_IDO_${_var_}}
${_IDO_${_var_}}:
	${RUN}${MKDIR} ${.TARGET:H}
	${RUN}					\
	(${ECHO} '#!${TOOLS_SHELL}';					\
	 ${ECHO} 'exec ${${_var_}PATH} "$$@"';			\
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

# Force the use of f2c-f77 for compiling Fortran.
_IDO_USE_F2C=	no
FCPATH=			/nonexistent
.if !exists(${FCPATH})
_IDO_USE_F2C=	yes
.endif
.if !empty(_IDO_USE_F2C:M[yY][eE][sS])
.  include "../../mk/compiler/f2c.mk"
.endif

.endif	# COMPILER_IDO_MK
