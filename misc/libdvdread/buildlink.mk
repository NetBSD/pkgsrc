# $NetBSD: buildlink.mk,v 1.1 2002/01/21 15:43:46 zuntum Exp $
#
# This Makefile fragment is included by packages that use libdvdread.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.libdvdread to the dependency pattern
#     for the version of libdvdread desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(LIBDVDREAD_BUILDLINK_MK)
LIBDVDREAD_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.libdvdread?=	libdvdread>=0.9.2
DEPENDS+=		${BUILDLINK_DEPENDS.libdvdread}:../../misc/libdvdread

EVAL_PREFIX+=		BUILDLINK_PREFIX.libdvdread=libdvdread
BUILDLINK_PREFIX.libdvdread=	${LOCALBASE}
BUILDLINK_FILES.libdvdread=	include/dvdread/*
BUILDLINK_FILES.libdvdread+=	lib/libdvdread.*

BUILDLINK_TARGETS.libdvdread=	libdvdread-buildlink
BUILDLINK_TARGETS+=	${BUILDLINK_TARGETS.libdvdread}

pre-configure: ${BUILDLINK_TARGETS.libdvdread}
libdvdread-buildlink: _BUILDLINK_USE

.endif	# LIBDVDREAD_BUILDLINK_MK
