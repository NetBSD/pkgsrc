# $NetBSD: buildlink3.mk,v 1.2 2023/02/07 01:40:43 pho Exp $

BUILDLINK_TREE+=	hs-memotrie

.if !defined(HS_MEMOTRIE_BUILDLINK3_MK)
HS_MEMOTRIE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-memotrie+=	hs-memotrie>=0.6.10
BUILDLINK_ABI_DEPENDS.hs-memotrie+=	hs-memotrie>=0.6.10nb1
BUILDLINK_PKGSRCDIR.hs-memotrie?=	../../devel/hs-memotrie

.include "../../devel/hs-newtype-generics/buildlink3.mk"
.endif	# HS_MEMOTRIE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-memotrie
