# $NetBSD: buildlink3.mk,v 1.29 2025/03/05 03:39:14 pho Exp $

BUILDLINK_TREE+=	hs-hashable

.if !defined(HS_HASHABLE_BUILDLINK3_MK)
HS_HASHABLE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hashable+=	hs-hashable>=1.5.0
BUILDLINK_ABI_DEPENDS.hs-hashable+=	hs-hashable>=1.5.0.0nb2
BUILDLINK_PKGSRCDIR.hs-hashable?=	../../devel/hs-hashable
.endif	# HS_HASHABLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hashable
