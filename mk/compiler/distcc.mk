# $NetBSD: distcc.mk,v 1.21 2004/11/17 17:18:33 tv Exp $

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
_DISTCC_LINKS=	# empty
.  if !empty(_LANGUAGES.distcc:Mc)
_DISTCC_CC:=	${_DISTCC_DIR}/bin/${PKG_CC:T}
_DISTCC_LINKS+=	_DISTCC_CC
PKG_CC:=	${_DISTCC_CC}
CC=		${PKG_CC:T}
.  endif
.  if !empty(_LANGUAGES.distcc:Mc++)
_DISTCC_CXX:=	${_DISTCC_DIR}/bin/${PKG_CXX:T}
_DISTCC_LINKS+=	_DISTCC_CXX
PKG_CXX:=	${_DISTCC_CXX}
CXX=		${PKG_CXX:T}
.  endif

# Prepend the path to the compiler to the PATH.
.  if !empty(_LANGUAGES.distcc)
PREPEND_PATH+=	${_DISTCC_DIR}/bin
.  endif

# Add the dependency on distcc.
BUILD_DEPENDS+=	distcc-[0-9]*:../../devel/distcc

.if defined(DISTCC_HOSTS) && !empty(DISTCC_HOSTS)
BUILD_ENV+=	DISTCC_HOSTS=${DISTCC_HOSTS:Q}
.endif
.if defined(DISTCC_SSH) && !empty(DISTCC_SSH)
BUILD_ENV+=	DISTCC_SSH=${DISTCC_SSH:Q}
.endif
.if defined(DISTCC_VERBOSE) && !empty(DISTCC_VERBOSE)
BUILD_ENV+=	DISTCC_VERBOSE=${DISTCC_VERBOSE:Q}
.endif

# Create symlinks for the compiler into ${WRKDIR}.
.  for _target_ in ${_DISTCC_LINKS}
.    if !target(${${_target_}})
override-tools: ${${_target_}}
${${_target_}}:
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${LN} -fs ${_DISTCCBASE}/bin/distcc ${.TARGET}
.    endif
.  endfor
.endif	# _USE_DISTCC == "yes"

.endif # COMPILER_DISTCC_MK
