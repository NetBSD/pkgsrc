# $NetBSD: buildlink3.mk,v 1.5 2020/01/01 02:55:02 pho Exp $

BUILDLINK_TREE+=	hs-mtl

.if !defined(HS_MTL_BUILDLINK3_MK)
HS_MTL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-mtl+=	hs-mtl>=2.2.2
BUILDLINK_ABI_DEPENDS.hs-mtl+=	hs-mtl>=2.2.2
BUILDLINK_PKGSRCDIR.hs-mtl?=	../../devel/hs-mtl
.endif	# HS_MTL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-mtl
