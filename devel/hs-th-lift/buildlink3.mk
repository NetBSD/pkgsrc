# $NetBSD: buildlink3.mk,v 1.6 2023/02/07 01:40:52 pho Exp $

BUILDLINK_TREE+=	hs-th-lift

.if !defined(HS_TH_LIFT_BUILDLINK3_MK)
HS_TH_LIFT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-th-lift+=	hs-th-lift>=0.8.2
BUILDLINK_ABI_DEPENDS.hs-th-lift+=	hs-th-lift>=0.8.2nb5
BUILDLINK_PKGSRCDIR.hs-th-lift?=	../../devel/hs-th-lift

.include "../../devel/hs-th-abstraction/buildlink3.mk"
.endif	# HS_TH_LIFT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-th-lift
