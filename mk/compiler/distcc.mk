# $NetBSD: distcc.mk,v 1.24 2005/01/10 19:38:53 jlam Exp $

.if !defined(COMPILER_DISTCC_MK)
COMPILER_DISTCC_MK=	defined

.include "../../mk/bsd.prefs.mk"

.if !empty(PKGPATH:Mdevel/distcc)
IGNORE_DISTCC=	yes
MAKEFLAGS+=	IGNORE_DISTCC=yes
.endif

.if defined(IGNORE_DISTCC)
_USE_DISTCC=	NO
.endif

# LANGUAGES.<compiler> is the list of supported languages by the compiler.
# _LANGUAGES.<compiler> is ${LANGUAGES.<compiler>} restricted to the ones
# requested by the package in USE_LANGUAGES.
# 
LANGUAGES.distcc=	c c++
_LANGUAGES.distcc=	# empty
.for _lang_ in ${USE_LANGUAGES}
_LANGUAGES.distcc+=	${LANGUAGES.distcc:M${_lang_}}
.endfor
.if empty(_LANGUAGES.distcc)
_USE_DISTCC=	NO
.endif

.if !defined(_USE_DISTCC)
_USE_DISTCC=	YES
.endif

.if !empty(_USE_DISTCC:M[yY][eE][sS])
EVAL_PREFIX+=		_DISTCCBASE=distcc
_DISTCCBASE_DEFAULT=	${LOCALBASE}
_DISTCCBASE?=		${LOCALBASE}

_DISTCC_DIR=	${WRKDIR}/.distcc
_DISTCC_VARS=	# empty
.  if !empty(_LANGUAGES.distcc:Mc)
PKG_CC?=	${CC}
_DISTCC_VARS+=	CC
_DISTCC_CC:=	${_DISTCC_DIR}/bin/${PKG_CC:T}
_ALIASES.CC+=	cc
PKG_CC:=	${_DISTCC_CC}
.  endif
.  if !empty(_LANGUAGES.distcc:Mc++)
PKG_CXX?=	${CXX}
_DISTCC_VARS+=	CXX
_DISTCC_CXX:=	${_DISTCC_DIR}/bin/${PKG_CXX:T}
_ALIASES.CXX+=	c++
PKG_CXX:=	${_DISTCC_CXX}
.  endif

# Prepend the path to the compiler to the PATH.
.  if !empty(_LANGUAGES.distcc)
PREPEND_PATH+=	${_DISTCC_DIR}/bin
.  endif

# Add the dependency on distcc.
BUILD_DEPENDS+=	distcc-[0-9]*:../../devel/distcc

.  if defined(DISTCC_HOSTS) && !empty(DISTCC_HOSTS)
BUILD_ENV+=	DISTCC_HOSTS=${DISTCC_HOSTS:Q}
.  endif
.  if defined(DISTCC_SSH) && !empty(DISTCC_SSH)
BUILD_ENV+=	DISTCC_SSH=${DISTCC_SSH:Q}
.  endif
.  if defined(DISTCC_VERBOSE) && !empty(DISTCC_VERBOSE)
BUILD_ENV+=	DISTCC_VERBOSE=${DISTCC_VERBOSE:Q}
.  endif

# Create symlinks for the compiler into ${WRKDIR}.
.  for _var_ in ${_DISTCC_VARS}
.    if !target(${_DISTCC_${_var_}})
override-tools: ${_DISTCC_${_var_}}
${_DISTCC_${_var_}}:
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${LN} -fs ${_DISTCCBASE}/bin/distcc ${.TARGET}
.      for _alias_ in ${_ALIASES.${_var_}:S/^/${.TARGET:H}\//}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	if [ ! -x "${_alias_}" ]; then					\
		${LN} -fs ${_DISTCCBASE}/bin/distcc ${_alias_};		\
	fi
.      endfor
.    endif
.  endfor
.endif	# _USE_DISTCC == "yes"

.endif # COMPILER_DISTCC_MK
