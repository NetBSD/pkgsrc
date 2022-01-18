# $NetBSD: buildlink3.mk,v 1.15 2022/01/18 02:48:08 pho Exp $

BUILDLINK_TREE+=	hs-hashable

.if !defined(HS_HASHABLE_BUILDLINK3_MK)
HS_HASHABLE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hashable+=	hs-hashable>=1.3.1
BUILDLINK_ABI_DEPENDS.hs-hashable+=	hs-hashable>=1.3.1.0nb3
BUILDLINK_PKGSRCDIR.hs-hashable?=	../../devel/hs-hashable
.endif	# HS_HASHABLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hashable
