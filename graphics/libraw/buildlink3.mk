# $NetBSD: buildlink3.mk,v 1.7 2019/07/10 20:27:59 nia Exp $

BUILDLINK_TREE+=	libraw

.if !defined(LIBRAW_BUILDLINK3_MK)
LIBRAW_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libraw+=	libraw>=0.16.0
BUILDLINK_ABI_DEPENDS.libraw+=	libraw>=0.19.3
BUILDLINK_PKGSRCDIR.libraw?=	../../graphics/libraw

.include "../../graphics/jasper/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.endif	# LIBRAW_BUILDLINK3_MK

BUILDLINK_TREE+=	-libraw
