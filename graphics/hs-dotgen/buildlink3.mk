# $NetBSD: buildlink3.mk,v 1.9 2025/08/13 11:07:09 pho Exp $

BUILDLINK_TREE+=	hs-dotgen

.if !defined(HS_DOTGEN_BUILDLINK3_MK)
HS_DOTGEN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-dotgen+=	hs-dotgen>=0.4.3
BUILDLINK_ABI_DEPENDS.hs-dotgen+=	hs-dotgen>=0.4.3nb8
BUILDLINK_PKGSRCDIR.hs-dotgen?=		../../graphics/hs-dotgen
.endif	# HS_DOTGEN_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-dotgen
