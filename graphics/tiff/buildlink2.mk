# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/05/11 02:09:16 jlam Exp $
#
# This Makefile fragment is included by packages that use libtiff.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.tiff to the dependency pattern
#     for the version of libtiff desired.
# (2) Include this Makefile fragment in the package Makefile.

.if !defined(TIFF_BUILDLINK2_MK)
TIFF_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.buildlink2.mk"

BUILDLINK_DEPENDS.tiff?=	tiff>=3.5.4
DEPENDS+=	${BUILDLINK_DEPENDS.tiff}:../../graphics/tiff

BUILDLINK_PREFIX.tiff=	${LOCALBASE}
BUILDLINK_FILES.tiff=	include/tiff.h
BUILDLINK_FILES.tiff+=	include/tiffconf.h
BUILDLINK_FILES.tiff+=	include/tiffio.h
BUILDLINK_FILES.tiff+=	include/tiffvers.h
BUILDLINK_FILES.tiff+=	lib/libtiff.*

.include "../../devel/zlib/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"

BUILDLINK_TARGETS+=	tiff-buildlink

tiff-buildlink: _BUILDLINK_USE

.endif	# TIFF_BUILDLINK2_MK
