# $NetBSD: buildlink3.mk,v 1.11 2025/03/05 03:39:07 pho Exp $

BUILDLINK_TREE+=	hs-constraints

.if !defined(HS_CONSTRAINTS_BUILDLINK3_MK)
HS_CONSTRAINTS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-constraints+=	hs-constraints>=0.14.2
BUILDLINK_ABI_DEPENDS.hs-constraints+=	hs-constraints>=0.14.2nb2
BUILDLINK_PKGSRCDIR.hs-constraints?=	../../devel/hs-constraints

.include "../../devel/hs-boring/buildlink3.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.endif	# HS_CONSTRAINTS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-constraints
