# $NetBSD: buildlink3.mk,v 1.2 2021/05/03 19:00:56 pho Exp $

BUILDLINK_TREE+=	hs-cereal

.if !defined(HS_CEREAL_BUILDLINK3_MK)
HS_CEREAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-cereal+=	hs-cereal>=0.5.8
BUILDLINK_ABI_DEPENDS.hs-cereal+=	hs-cereal>=0.5.8.1nb1
BUILDLINK_PKGSRCDIR.hs-cereal?=		../../devel/hs-cereal
.endif	# HS_CEREAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-cereal
