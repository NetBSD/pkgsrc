# $NetBSD: buildlink.mk,v 1.13 2001/08/20 03:54:48 jlam Exp $
#
# This Makefile fragment is included by packages that use getopt_long().
#
# To use this Makefile fragment, simply:
#
# (1) Include this Makefile fragment in the package Makefile,
# (2) Optionally define BUILDLINK_INCDIR and BUILDLINK_LIBDIR,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path.
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(GETOPT_BUILDLINK_MK)
GETOPT_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.getopt?=	libgetopt>=1.3

.if exists(/usr/include/getopt.h)
_NEED_GETOPT=		NO
.else
_NEED_GETOPT=		YES
.endif

.if ${_NEED_GETOPT} == "NO"
BUILDLINK_PREFIX.getopt=	/usr
BUILDLINK_FILES.getopt=		include/getopt.h
LIBGETOPT=			# empty
.else
DEPENDS+=	${BUILDLINK_DEPENDS.getopt}:../../devel/libgetopt
EVAL_PREFIX+=			BUILDLINK_PREFIX.getopt=libgetopt
BUILDLINK_PREFIX.getopt_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.getopt=		include/getopt.h
BUILDLINK_FILES.getopt+=	lib/libgetopt.*
BUILDLINK_FILES.getopt+=	lib/libgetopt_pic.a
LIBGETOPT=			-lgetopt
.endif

CONFIGURE_ENV+=			LIBGETOPT="${LIBGETOPT}"
MAKE_ENV+=			LIBGETOPT="${LIBGETOPT}"

BUILDLINK_TARGETS.getopt=	getopt-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.getopt}

pre-configure: ${BUILDLINK_TARGETS.getopt}
getopt-buildlink: _BUILDLINK_USE

.endif	# GETOPT_BUILDLINK_MK
