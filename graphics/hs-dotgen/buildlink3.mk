# $NetBSD: buildlink3.mk,v 1.2 2022/02/26 03:58:14 pho Exp $

BUILDLINK_TREE+=	hs-dotgen

.if !defined(HS_DOTGEN_BUILDLINK3_MK)
HS_DOTGEN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-dotgen+=	hs-dotgen>=0.4.3
BUILDLINK_ABI_DEPENDS.hs-dotgen+=	hs-dotgen>=0.4.3nb1
BUILDLINK_PKGSRCDIR.hs-dotgen?=		../../graphics/hs-dotgen
.endif	# HS_DOTGEN_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-dotgen
