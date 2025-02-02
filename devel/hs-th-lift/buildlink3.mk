# $NetBSD: buildlink3.mk,v 1.12 2025/02/02 13:05:27 pho Exp $

BUILDLINK_TREE+=	hs-th-lift

.if !defined(HS_TH_LIFT_BUILDLINK3_MK)
HS_TH_LIFT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-th-lift+=	hs-th-lift>=0.8.6
BUILDLINK_ABI_DEPENDS.hs-th-lift+=	hs-th-lift>=0.8.6nb1
BUILDLINK_PKGSRCDIR.hs-th-lift?=	../../devel/hs-th-lift

.include "../../devel/hs-th-abstraction/buildlink3.mk"
.endif	# HS_TH_LIFT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-th-lift
