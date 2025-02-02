# $NetBSD: buildlink3.mk,v 1.7 2025/02/02 13:05:14 pho Exp $

BUILDLINK_TREE+=	hs-memotrie

.if !defined(HS_MEMOTRIE_BUILDLINK3_MK)
HS_MEMOTRIE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-memotrie+=	hs-memotrie>=0.6.11
BUILDLINK_ABI_DEPENDS.hs-memotrie+=	hs-memotrie>=0.6.11nb3
BUILDLINK_PKGSRCDIR.hs-memotrie?=	../../devel/hs-memotrie

.include "../../devel/hs-newtype-generics/buildlink3.mk"
.endif	# HS_MEMOTRIE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-memotrie
