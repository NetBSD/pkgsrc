# $NetBSD: buildlink3.mk,v 1.5 2023/11/02 06:37:06 pho Exp $

BUILDLINK_TREE+=	hs-dotgen

.if !defined(HS_DOTGEN_BUILDLINK3_MK)
HS_DOTGEN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-dotgen+=	hs-dotgen>=0.4.3
BUILDLINK_ABI_DEPENDS.hs-dotgen+=	hs-dotgen>=0.4.3nb4
BUILDLINK_PKGSRCDIR.hs-dotgen?=		../../graphics/hs-dotgen
.endif	# HS_DOTGEN_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-dotgen
