# $NetBSD: buildlink3.mk,v 1.5 2023/10/09 04:54:10 pho Exp $

BUILDLINK_TREE+=	hs-constraints-extras

.if !defined(HS_CONSTRAINTS_EXTRAS_BUILDLINK3_MK)
HS_CONSTRAINTS_EXTRAS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-constraints-extras+=	hs-constraints-extras>=0.4.0
BUILDLINK_ABI_DEPENDS.hs-constraints-extras+=	hs-constraints-extras>=0.4.0.0nb2
BUILDLINK_PKGSRCDIR.hs-constraints-extras?=	../../devel/hs-constraints-extras

.include "../../devel/hs-constraints/buildlink3.mk"
.endif	# HS_CONSTRAINTS_EXTRAS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-constraints-extras
