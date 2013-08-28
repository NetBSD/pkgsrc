# $NetBSD: buildlink3.mk,v 1.24 2013/08/28 16:51:36 richard Exp $

BUILDLINK_TREE+=	tiff

.if !defined(TIFF_BUILDLINK3_MK)
TIFF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tiff+=	tiff>=3.6.1
BUILDLINK_ABI_DEPENDS.tiff+=	tiff>=4.0.3nb5
BUILDLINK_PKGSRCDIR.tiff?=	../../graphics/tiff

.include "../../devel/zlib/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../graphics/jbigkit/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.endif # TIFF_BUILDLINK3_MK

BUILDLINK_TREE+=	-tiff
