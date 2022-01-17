# $NetBSD: buildlink3.mk,v 1.14 2022/01/17 05:06:55 pho Exp $

BUILDLINK_TREE+=	hs-hashable

.if !defined(HS_HASHABLE_BUILDLINK3_MK)
HS_HASHABLE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hashable+=	hs-hashable>=1.3.1
BUILDLINK_ABI_DEPENDS.hs-hashable+=	hs-hashable>=1.3.1.0nb2
BUILDLINK_PKGSRCDIR.hs-hashable?=	../../devel/hs-hashable
.endif	# HS_HASHABLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hashable
