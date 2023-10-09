# $NetBSD: buildlink3.mk,v 1.7 2023/10/09 04:54:32 pho Exp $

BUILDLINK_TREE+=	hs-th-lift-instances

.if !defined(HS_TH_LIFT_INSTANCES_BUILDLINK3_MK)
HS_TH_LIFT_INSTANCES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-th-lift-instances+=	hs-th-lift-instances>=0.1.20
BUILDLINK_ABI_DEPENDS.hs-th-lift-instances+=	hs-th-lift-instances>=0.1.20nb2
BUILDLINK_PKGSRCDIR.hs-th-lift-instances?=	../../devel/hs-th-lift-instances

.include "../../devel/hs-th-lift/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.endif	# HS_TH_LIFT_INSTANCES_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-th-lift-instances
