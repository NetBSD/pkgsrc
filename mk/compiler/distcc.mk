# $NetBSD: distcc.mk,v 1.1 2004/02/01 00:31:00 jlam Exp $

.if !defined(COMPILER_DISTCC_MK)
COMPILER_DISTCC_MK=	defined

.if !empty(PKGPATH:Mdevel/distcc)
IGNORE_DISTCC=	yes
MAKEFLAGS+=	IGNORE_DISTCC=yes
.endif

.if defined(IGNORE_DISTCC)
_USE_DISTCC=	NO
.endif

.if !defined(_USE_DISTCC)
_USE_DISTCC=	YES
.endif

.if !empty(_USE_DISTCC:M[yY][eE][sS])
#
# Add the dependency on distcc.
BUILD_DEPENDS+=	distcc-[0-9]*:../../devel/distcc
.endif

EVAL_PREFIX+=	_DISTCCBASE=distcc
_DISTCCBASE_DEFAULT=	${LOCALBASE}
_DISTCCBASE?=		${LOCALBASE}

.if exists(${_DISTCCBASE}/bin/distcc)
_DISTCC_DIR=	${WRKDIR}/.distcc
PATH:=		${_DISTCC_DIR}/bin:${PATH}

CC=		${_DISTCC_DIR}/bin/cc
CXX=		${_DISTCC_DIR}/bin/c++

.  for _target_ in CC CXX
override-tools: ${${_target_}}
${${_target_}}:
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${LN} -fs ${_DISTCCBASE}/bin/distcc ${.TARGET}
.  endfor
.endif

.endif	# COMPILER_DISTCC_MK
