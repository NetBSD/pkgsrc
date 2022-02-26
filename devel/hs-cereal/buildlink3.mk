# $NetBSD: buildlink3.mk,v 1.6 2022/02/26 03:57:50 pho Exp $

BUILDLINK_TREE+=	hs-cereal

.if !defined(HS_CEREAL_BUILDLINK3_MK)
HS_CEREAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-cereal+=	hs-cereal>=0.5.8
BUILDLINK_ABI_DEPENDS.hs-cereal+=	hs-cereal>=0.5.8.2nb2
BUILDLINK_PKGSRCDIR.hs-cereal?=		../../devel/hs-cereal
.endif	# HS_CEREAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-cereal
