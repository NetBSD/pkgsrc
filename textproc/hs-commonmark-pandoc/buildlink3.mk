# $NetBSD: buildlink3.mk,v 1.13 2024/05/09 01:32:41 pho Exp $

BUILDLINK_TREE+=	hs-commonmark-pandoc

.if !defined(HS_COMMONMARK_PANDOC_BUILDLINK3_MK)
HS_COMMONMARK_PANDOC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-commonmark-pandoc+=	hs-commonmark-pandoc>=0.2.2
BUILDLINK_ABI_DEPENDS.hs-commonmark-pandoc+=	hs-commonmark-pandoc>=0.2.2.1nb1
BUILDLINK_PKGSRCDIR.hs-commonmark-pandoc?=	../../textproc/hs-commonmark-pandoc

.include "../../textproc/hs-commonmark/buildlink3.mk"
.include "../../textproc/hs-commonmark-extensions/buildlink3.mk"
.include "../../textproc/hs-pandoc-types/buildlink3.mk"
.endif	# HS_COMMONMARK_PANDOC_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-commonmark-pandoc
