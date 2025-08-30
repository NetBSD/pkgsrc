# $NetBSD: buildlink3.mk,v 1.18 2025/08/30 22:45:36 wiz Exp $

BUILDLINK_TREE+=	vigra

.if !defined(VIGRA_BUILDLINK3_MK)
VIGRA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.vigra+=	vigra>=1.10.0
BUILDLINK_ABI_DEPENDS.vigra+=	vigra>=1.12.2nb3
BUILDLINK_PKGSRCDIR.vigra?=	../../graphics/vigra

.include "../../devel/hdf5/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.endif	# VIGRA_BUILDLINK3_MK

BUILDLINK_TREE+=	-vigra
