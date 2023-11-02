# $NetBSD: buildlink3.mk,v 1.24 2023/11/02 06:36:33 pho Exp $

BUILDLINK_TREE+=	hs-hashable

.if !defined(HS_HASHABLE_BUILDLINK3_MK)
HS_HASHABLE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hashable+=	hs-hashable>=1.4.3
BUILDLINK_ABI_DEPENDS.hs-hashable+=	hs-hashable>=1.4.3.0nb1
BUILDLINK_PKGSRCDIR.hs-hashable?=	../../devel/hs-hashable
.endif	# HS_HASHABLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hashable
