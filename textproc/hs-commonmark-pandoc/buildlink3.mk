# $NetBSD: buildlink3.mk,v 1.3 2022/01/18 02:48:25 pho Exp $

BUILDLINK_TREE+=	hs-commonmark-pandoc

.if !defined(HS_COMMONMARK_PANDOC_BUILDLINK3_MK)
HS_COMMONMARK_PANDOC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-commonmark-pandoc+=	hs-commonmark-pandoc>=0.2.0
BUILDLINK_ABI_DEPENDS.hs-commonmark-pandoc+=	hs-commonmark-pandoc>=0.2.0.1nb2
BUILDLINK_PKGSRCDIR.hs-commonmark-pandoc?=	../../textproc/hs-commonmark-pandoc

.include "../../textproc/hs-commonmark/buildlink3.mk"
.include "../../textproc/hs-commonmark-extensions/buildlink3.mk"
.include "../../textproc/hs-pandoc-types/buildlink3.mk"
.endif	# HS_COMMONMARK_PANDOC_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-commonmark-pandoc
