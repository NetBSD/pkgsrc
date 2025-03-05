# $NetBSD: buildlink3.mk,v 1.8 2025/03/05 03:39:38 pho Exp $

BUILDLINK_TREE+=	hs-dotgen

.if !defined(HS_DOTGEN_BUILDLINK3_MK)
HS_DOTGEN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-dotgen+=	hs-dotgen>=0.4.3
BUILDLINK_ABI_DEPENDS.hs-dotgen+=	hs-dotgen>=0.4.3nb7
BUILDLINK_PKGSRCDIR.hs-dotgen?=		../../graphics/hs-dotgen
.endif	# HS_DOTGEN_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-dotgen
