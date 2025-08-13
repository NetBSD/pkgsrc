# $NetBSD: buildlink3.mk,v 1.11 2025/08/13 11:07:35 pho Exp $

BUILDLINK_TREE+=	hs-skylighting-format-blaze-html

.if !defined(HS_SKYLIGHTING_FORMAT_BLAZE_HTML_BUILDLINK3_MK)
HS_SKYLIGHTING_FORMAT_BLAZE_HTML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-skylighting-format-blaze-html+=	hs-skylighting-format-blaze-html>=0.1.1
BUILDLINK_ABI_DEPENDS.hs-skylighting-format-blaze-html+=	hs-skylighting-format-blaze-html>=0.1.1.3nb3
BUILDLINK_PKGSRCDIR.hs-skylighting-format-blaze-html?=		../../textproc/hs-skylighting-format-blaze-html

.include "../../textproc/hs-blaze-html/buildlink3.mk"
.include "../../textproc/hs-skylighting-core/buildlink3.mk"
.endif	# HS_SKYLIGHTING_FORMAT_BLAZE_HTML_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-skylighting-format-blaze-html
