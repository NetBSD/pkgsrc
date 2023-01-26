# $NetBSD: buildlink3.mk,v 1.3 2023/01/26 08:46:54 pho Exp $

BUILDLINK_TREE+=	hs-constraints

.if !defined(HS_CONSTRAINTS_BUILDLINK3_MK)
HS_CONSTRAINTS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-constraints+=	hs-constraints>=0.13.4
BUILDLINK_ABI_DEPENDS.hs-constraints+=	hs-constraints>=0.13.4
BUILDLINK_PKGSRCDIR.hs-constraints?=	../../devel/hs-constraints

.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../devel/hs-transformers-compat/buildlink3.mk"
.include "../../devel/hs-type-equality/buildlink3.mk"
.endif	# HS_CONSTRAINTS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-constraints
