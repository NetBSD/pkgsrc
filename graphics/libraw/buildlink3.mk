# $NetBSD: buildlink3.mk,v 1.6 2015/07/18 10:40:20 adam Exp $

BUILDLINK_TREE+=	libraw

.if !defined(LIBRAW_BUILDLINK3_MK)
LIBRAW_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libraw+=	libraw>=0.16.0
BUILDLINK_ABI_DEPENDS.libraw+=	libraw>=0.16.0
BUILDLINK_PKGSRCDIR.libraw?=	../../graphics/libraw

.include "../../graphics/jasper/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.endif	# LIBRAW_BUILDLINK3_MK

BUILDLINK_TREE+=	-libraw
