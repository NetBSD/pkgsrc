# $NetBSD: buildlink.mk,v 1.7 2001/06/11 01:59:34 jlam Exp $
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

.if exists(/usr/include/getopt.h)
BUILDLINK_PREFIX.getopt=	/usr
BUILDLINK_FILES.getopt=		include/getopt.h
.else
DEPENDS+=			libgetopt>=1.3:../../devel/libgetopt
BUILDLINK_PREFIX.getopt=	${LOCALBASE}
BUILDLINK_FILES.getopt=		include/getopt.h
BUILDLINK_FILES.getopt+=	lib/libgetopt.*
BUILDLINK_FILES.getopt+=	lib/libgetopt_pic.a

.if defined(GNU_CONFIGURE)
CONFIGURE_ENV+=			LIBS="${LIBS}"
LIBS+=				-lgetopt
.endif
.endif

BUILDLINK_TARGETS.getopt=	getopt-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.getopt}

pre-configure: ${BUILDLINK_TARGETS.getopt}
getopt-buildlink: _BUILDLINK_USE

.include "../../mk/bsd.buildlink.mk"

.endif	# GETOPT_BUILDLINK_MK
