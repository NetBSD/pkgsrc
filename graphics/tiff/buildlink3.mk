# $NetBSD: buildlink3.mk,v 1.22 2013/01/26 21:36:32 adam Exp $

BUILDLINK_TREE+=	tiff

.if !defined(TIFF_BUILDLINK3_MK)
TIFF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tiff+=	tiff>=3.6.1
BUILDLINK_ABI_DEPENDS.tiff+=	tiff>=4.0.3nb2
BUILDLINK_PKGSRCDIR.tiff?=	../../graphics/tiff

.include "../../devel/zlib/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.endif # TIFF_BUILDLINK3_MK

BUILDLINK_TREE+=	-tiff
