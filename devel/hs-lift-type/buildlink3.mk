# $NetBSD: buildlink3.mk,v 1.3 2024/05/09 01:32:01 pho Exp $

BUILDLINK_TREE+=	hs-lift-type

.if !defined(HS_LIFT_TYPE_BUILDLINK3_MK)
HS_LIFT_TYPE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-lift-type+=	hs-lift-type>=0.1.1
BUILDLINK_ABI_DEPENDS.hs-lift-type+=	hs-lift-type>=0.1.1.1nb2
BUILDLINK_PKGSRCDIR.hs-lift-type?=	../../devel/hs-lift-type
.endif	# HS_LIFT_TYPE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-lift-type
