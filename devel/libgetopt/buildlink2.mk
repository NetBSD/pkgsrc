# $NetBSD: buildlink2.mk,v 1.1.2.2 2002/06/06 06:54:36 jlam Exp $
#
# This Makefile fragment is included by packages that use getopt_long().
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.getopt to the dependency pattern
#     for the version of libgetopt desired.
# (2) Include this Makefile fragment in the package Makefile.

.if !defined(GETOPT_BUILDLINK2_MK)
GETOPT_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.buildlink2.mk"

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
EVAL_PREFIX+=	BUILDLINK_PREFIX.getopt=libgetopt
BUILDLINK_PREFIX.getopt_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.getopt=		include/getopt.h
BUILDLINK_FILES.getopt+=	lib/libgetopt.*
BUILDLINK_FILES.getopt+=	lib/libgetopt_pic.a
LIBGETOPT=			-lgetopt
.endif

CONFIGURE_ENV+=			LIBGETOPT="${LIBGETOPT}"
MAKE_ENV+=			LIBGETOPT="${LIBGETOPT}"

BUILDLINK_TARGETS+=		getopt-buildlink

getopt-buildlink: _BUILDLINK_USE

.endif	# GETOPT_BUILDLINK2_MK
