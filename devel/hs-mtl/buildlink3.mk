# $NetBSD: buildlink3.mk,v 1.1 2014/05/16 20:31:58 szptvlfn Exp $

BUILDLINK_TREE+=	hs-mtl

.if !defined(HS_MTL_BUILDLINK3_MK)
HS_MTL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-mtl+=	hs-mtl>=2.2.0
BUILDLINK_PKGSRCDIR.hs-mtl?=	../../devel/hs-mtl

.include "../../devel/hs-transformers/buildlink3.mk"
.endif	# HS_MTL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-mtl
