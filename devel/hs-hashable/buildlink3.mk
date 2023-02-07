# $NetBSD: buildlink3.mk,v 1.21 2023/02/07 01:40:36 pho Exp $

BUILDLINK_TREE+=	hs-hashable

.if !defined(HS_HASHABLE_BUILDLINK3_MK)
HS_HASHABLE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hashable+=	hs-hashable>=1.4.2
BUILDLINK_ABI_DEPENDS.hs-hashable+=	hs-hashable>=1.4.2.0nb1
BUILDLINK_PKGSRCDIR.hs-hashable?=	../../devel/hs-hashable

.include "../../devel/hs-data-array-byte/buildlink3.mk"
.endif	# HS_HASHABLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hashable
