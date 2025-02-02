# $NetBSD: buildlink3.mk,v 1.12 2025/02/02 13:05:00 pho Exp $

BUILDLINK_TREE+=	hs-cereal

.if !defined(HS_CEREAL_BUILDLINK3_MK)
HS_CEREAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-cereal+=	hs-cereal>=0.5.8
BUILDLINK_ABI_DEPENDS.hs-cereal+=	hs-cereal>=0.5.8.3nb5
BUILDLINK_PKGSRCDIR.hs-cereal?=		../../devel/hs-cereal
.endif	# HS_CEREAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-cereal
