# $NetBSD: buildlink2.mk,v 1.1.2.2 2002/06/06 06:54:42 jlam Exp $
#
# This Makefile fragment is included by packages that use libpng.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.png to the dependency pattern
#     for the version of libpng desired.
# (2) Include this Makefile fragment in the package Makefile.

.if !defined(PNG_BUILDLINK2_MK)
PNG_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.buildlink2.mk"

BUILDLINK_DEPENDS.png?=	png>=1.2.1
DEPENDS+=		${BUILDLINK_DEPENDS.png}:../../graphics/png

EVAL_PREFIX+=	BUILDLINK_PREFIX.png=png
BUILDLINK_PREFIX.png_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.png=	include/png.h
BUILDLINK_FILES.png+=	include/pngconf.h
BUILDLINK_FILES.png+=	lib/libpng.*

.include "../../devel/zlib/buildlink2.mk"

BUILDLINK_TARGETS+=	png-buildlink

png-buildlink: _BUILDLINK_USE

.endif	# PNG_BUILDLINK2_MK
