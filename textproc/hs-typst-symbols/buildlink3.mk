# $NetBSD: buildlink3.mk,v 1.1 2023/10/24 07:45:01 pho Exp $

BUILDLINK_TREE+=	hs-typst-symbols

.if !defined(HS_TYPST_SYMBOLS_BUILDLINK3_MK)
HS_TYPST_SYMBOLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-typst-symbols+=	hs-typst-symbols>=0.1.4
BUILDLINK_ABI_DEPENDS.hs-typst-symbols+=	hs-typst-symbols>=0.1.4
BUILDLINK_PKGSRCDIR.hs-typst-symbols?=		../../textproc/hs-typst-symbols
.endif	# HS_TYPST_SYMBOLS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-typst-symbols
