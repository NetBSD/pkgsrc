# $NetBSD: buildlink3.mk,v 1.1 2021/04/25 04:07:07 pho Exp $

BUILDLINK_TREE+=	hs-commonmark-pandoc

.if !defined(HS_COMMONMARK_PANDOC_BUILDLINK3_MK)
HS_COMMONMARK_PANDOC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-commonmark-pandoc+=	hs-commonmark-pandoc>=0.2.0
BUILDLINK_ABI_DEPENDS.hs-commonmark-pandoc+=	hs-commonmark-pandoc>=0.2.0.1
BUILDLINK_PKGSRCDIR.hs-commonmark-pandoc?=	../../textproc/hs-commonmark-pandoc

.include "../../textproc/hs-commonmark/buildlink3.mk"
.include "../../textproc/hs-commonmark-extensions/buildlink3.mk"
.include "../../textproc/hs-pandoc-types/buildlink3.mk"
.endif	# HS_COMMONMARK_PANDOC_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-commonmark-pandoc
