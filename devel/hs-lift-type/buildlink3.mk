# $NetBSD: buildlink3.mk,v 1.6 2025/03/05 03:39:18 pho Exp $

BUILDLINK_TREE+=	hs-lift-type

.if !defined(HS_LIFT_TYPE_BUILDLINK3_MK)
HS_LIFT_TYPE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-lift-type+=	hs-lift-type>=0.1.2
BUILDLINK_ABI_DEPENDS.hs-lift-type+=	hs-lift-type>=0.1.2.0nb2
BUILDLINK_PKGSRCDIR.hs-lift-type?=	../../devel/hs-lift-type
.endif	# HS_LIFT_TYPE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-lift-type
