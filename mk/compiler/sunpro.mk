# $NetBSD: sunpro.mk,v 1.38 2007/03/09 09:59:21 rillig Exp $
#
# This is the compiler definition for the SUNWspro C compiler.
#
# User-settable variables:
#
# SUNWSPROBASE
#	The base directory where the compiler is installed.
#

.if !defined(COMPILER_SUNPRO_MK)
COMPILER_SUNPRO_MK=	defined

.include "../../mk/bsd.prefs.mk"

SUNWSPROBASE?=		/opt/SUNWspro

# common definitions
_COMPILER_TYPE.c=	CC
_COMPILER_TYPE.c++ =	CXX
_COMPILER_TYPE.fortran=	FC
_ALIASES.c=		cc gcc
_ALIASES.c++ =		CC g++ c++
_ALIASES.fortran=	f77 g77

# sunpro-specific definitions
_COMPILER_LANGS=	c c++ fortran
_COMPILER_NAME.c=	cc
_COMPILER_NAME.c++ =	CC
_COMPILER_NAME.fortran=	f77

# LANGUAGES.<compiler> is the list of supported languages by the
# compiler.
#
LANGUAGES.sunpro=	# empty

_SUNPRO_DIR=		${WRKDIR}/.sunpro
_SUNPRO_VARS=		# empty

.for l in ${_COMPILER_LANGS}
.  for t in ${_COMPILER_TYPE.${l}}
.    for n in ${_COMPILER_NAME.${l}}
.      if exists(${SUNWSPROBASE}/bin/${n})
LANGUAGES.sunpro+=	${l}
_SUNPRO_VARS+=		${t}
_SUNPRO_${t}=		${_SUNPRO_DIR}/bin/${n}
_ALIASES.${t}=		${ALIASES.${l}}
${t}PATH=		${SUNWSPROBASE}/bin/${n}
PKG_${t}:=		${_SUNPRO_${t}}
.      endif
.    endfor
.  endfor
.endfor
_COMPILER_STRIP_VARS+=	${_SUNPRO_VARS}

# The Solaris linker uses "-R" for rpath directives.
_LINKER_RPATH_FLAG=	-R

# SunPro passes rpath directives to the linker using "-R", however
# some packages require the "-Wl," prefix to recognize linker options.
# This is transformed by the compiler wrapper to "-R".
_COMPILER_RPATH_FLAG=	-Wl,-R

# SunPro compiler must be passed certain flags to compile/link 64-bit code.
.if ${MACHINE_ARCH} == "sparc"
_COMPILER_ABI_FLAG.64=	-xtarget=ultra -xarch=v9
.else
_COMPILER_ABI_FLAG.64= -xarch=amd64
.endif

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
#_SUNPRO_USE_F2C=	no
#FCPATH=			/nonexistent
#.if !exists(${FCPATH})
#_SUNPRO_USE_F2C=	yes
#.endif
#.if !empty(_SUNPRO_USE_F2C:M[yY][eE][sS])
# libtool keys off of the compiler name when configuring.  The unfortunate
# side effect is that if we let "f2c-f77" be called "f77" on solaris then
# libtool thinks we're using the Sun fortran compiler and it will add
# '-Qoption ld' to the compiler flags which get passed to the C compiler and
# those are not understood.  So make sure we call the compiler g77 instead.
#FC=	g77
#.  include "../../mk/compiler/f2c.mk"
#.endif

.endif	# COMPILER_SUNPRO_MK
