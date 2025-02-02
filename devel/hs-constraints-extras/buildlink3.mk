# $NetBSD: buildlink3.mk,v 1.9 2025/02/02 13:05:01 pho Exp $

BUILDLINK_TREE+=	hs-constraints-extras

.if !defined(HS_CONSTRAINTS_EXTRAS_BUILDLINK3_MK)
HS_CONSTRAINTS_EXTRAS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-constraints-extras+=	hs-constraints-extras>=0.4.0
BUILDLINK_ABI_DEPENDS.hs-constraints-extras+=	hs-constraints-extras>=0.4.0.2nb1
BUILDLINK_PKGSRCDIR.hs-constraints-extras?=	../../devel/hs-constraints-extras

.include "../../devel/hs-constraints/buildlink3.mk"
.endif	# HS_CONSTRAINTS_EXTRAS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-constraints-extras
