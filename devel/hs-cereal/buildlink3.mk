# $NetBSD: buildlink3.mk,v 1.1 2020/01/16 16:27:58 pho Exp $

BUILDLINK_TREE+=	hs-cereal

.if !defined(HS_CEREAL_BUILDLINK3_MK)
HS_CEREAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-cereal+=	hs-cereal>=0.5.8
BUILDLINK_ABI_DEPENDS.hs-cereal+=	hs-cereal>=0.5.8.1
BUILDLINK_PKGSRCDIR.hs-cereal?=		../../devel/hs-cereal
.endif	# HS_CEREAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-cereal
