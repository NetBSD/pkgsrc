# $NetBSD: buildlink.mk,v 1.3 2002/02/25 09:01:42 martti Exp $
#
# This Makefile fragment is included by packages that use libexif.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.libexif to the dependency pattern
#     for the version of libexif desired.
# (2) Include this Makefile fragment in the package Makefile.

.if !defined(LIBEXIF_BUILDLINK_MK)
LIBEXIF_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.libexif?=	libexif>=0.5
DEPENDS+=	${BUILDLINK_DEPENDS.libexif}:../../graphics/libexif

EVAL_PREFIX+=		BUILDLINK_PREFIX.libexif=libexif
BUILDLINK_PREFIX.libexif=	${LOCALBASE}
BUILDLINK_FILES.libexif=	include/libexif/*.h
BUILDLINK_FILES.libexif+=	lib/libexif.*

BUILDLINK_TARGETS.libexif=	libexif-buildlink
BUILDLINK_TARGETS+=	${BUILDLINK_TARGETS.libexif}

pre-configure: ${BUILDLINK_TARGETS.libexif}
libexif-buildlink: _BUILDLINK_USE

.endif	# LIBEXIF_BUILDLINK_MK
