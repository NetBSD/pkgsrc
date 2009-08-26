# $NetBSD: buildlink3.mk,v 1.17 2009/08/26 19:56:38 sno Exp $

BUILDLINK_TREE+=	tiff

.if !defined(TIFF_BUILDLINK3_MK)
TIFF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tiff+=	tiff>=3.6.1
BUILDLINK_ABI_DEPENDS.tiff+=	tiff>=3.9.0nb1
BUILDLINK_PKGSRCDIR.tiff?=	../../graphics/tiff

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.endif # TIFF_BUILDLINK3_MK

BUILDLINK_TREE+=	-tiff
