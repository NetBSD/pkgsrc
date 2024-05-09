# $NetBSD: buildlink3.mk,v 1.6 2024/05/09 01:32:03 pho Exp $

BUILDLINK_TREE+=	hs-memotrie

.if !defined(HS_MEMOTRIE_BUILDLINK3_MK)
HS_MEMOTRIE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-memotrie+=	hs-memotrie>=0.6.11
BUILDLINK_ABI_DEPENDS.hs-memotrie+=	hs-memotrie>=0.6.11nb2
BUILDLINK_PKGSRCDIR.hs-memotrie?=	../../devel/hs-memotrie

.include "../../devel/hs-newtype-generics/buildlink3.mk"
.endif	# HS_MEMOTRIE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-memotrie
