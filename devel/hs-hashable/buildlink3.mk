# $NetBSD: buildlink3.mk,v 1.16 2022/02/11 13:00:37 pho Exp $

BUILDLINK_TREE+=	hs-hashable

.if !defined(HS_HASHABLE_BUILDLINK3_MK)
HS_HASHABLE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hashable+=	hs-hashable>=1.4.0
BUILDLINK_ABI_DEPENDS.hs-hashable+=	hs-hashable>=1.4.0.2
BUILDLINK_PKGSRCDIR.hs-hashable?=	../../devel/hs-hashable
.endif	# HS_HASHABLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hashable
