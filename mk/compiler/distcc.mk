# $NetBSD: distcc.mk,v 1.11 2004/02/05 03:39:17 jlam Exp $

.if !defined(COMPILER_DISTCC_MK)
COMPILER_DISTCC_MK=	one

.  if !empty(PKGPATH:Mdevel/distcc)
IGNORE_DISTCC=	yes
MAKEFLAGS+=	IGNORE_DISTCC=yes
.  endif

.  if defined(IGNORE_DISTCC)
_USE_DISTCC=	NO
.  endif

# LANGUAGES.<compiler> is the list of supported languages by the compiler.
# _LANGUAGES.<compiler> is ${LANGUAGES.<compiler>} restricted to the ones
# requested by the package in USE_LANGUAGES.
# 
LANGUAGES.distcc=	c c++
_LANGUAGES.distcc=	# empty
.  for _lang_ in ${USE_LANGUAGES}
_LANGUAGES.distcc+=	${LANGUAGES.distcc:M${_lang_}}
.  endfor
.  if empty(_LANGUAGES.distcc)
_USE_DISTCC=	NO
.  endif

.  if !defined(_USE_DISTCC)
_USE_DISTCC=	YES
.  endif

.  if !empty(_USE_DISTCC:M[yY][eE][sS])
EVAL_PREFIX+=	_DISTCCBASE=distcc
_DISTCCBASE_DEFAULT=	${LOCALBASE}
_DISTCCBASE?=		${LOCALBASE}

.    if exists(${_DISTCCBASE}/bin/distcc)
_DISTCC_DIR=	${WRKDIR}/.distcc
_DISTCC_LINKS=	# empty
.      if !empty(_LANGUAGES.distcc:Mc)
CC:=	${_DISTCC_DIR}/bin/${CC:T}
_DISTCC_LINKS+=	CC
.      endif
.      if !empty(_LANGUAGES.distcc:Mc++)
CXX:=	${_DISTCC_DIR}/bin/${CXX:T}
_DISTCC_LINKS+=	CXX
.      endif
.    endif
.  endif
.endif	# COMPILER_DISTCC_MK

# The following section is included only if we're not being included by
# bsd.prefs.mk.
#
.if empty(BSD_PREFS_MK)
.  if empty(COMPILER_DISTCC_MK:Mtwo)
COMPILER_DISTCC_MK+=	two

.    if !empty(_USE_DISTCC:M[yY][eE][sS])
.      if !empty(_LANGUAGES.distcc)
PATH:=	${_DISTCC_DIR}/bin:${PATH}
.      endif

BUILD_DEPENDS+=	distcc-[0-9]*:../../devel/distcc

.      if exists(${_DISTCCBASE}/bin/distcc)
.        for _target_ in ${_DISTCC_LINKS}
override-tools: ${${_target_}}
${${_target_}}:
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${LN} -fs ${_DISTCCBASE}/bin/distcc ${.TARGET}
.        endfor
.      endif
.    endif
.  endif # COMPILER_DISTCC_MK
.endif	 # BSD_PREFS_MK
