# $NetBSD: buildlink3.mk,v 1.7 2013/01/26 21:36:33 adam Exp $

BUILDLINK_TREE+=	vigra

.if !defined(VIGRA_BUILDLINK3_MK)
VIGRA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.vigra+=	vigra>=1.7.0
BUILDLINK_ABI_DEPENDS.vigra+=	vigra>=1.9.0nb1
BUILDLINK_PKGSRCDIR.vigra?=	../../graphics/vigra

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.endif	# VIGRA_BUILDLINK3_MK

BUILDLINK_TREE+=	-vigra
