# $NetBSD: buildlink3.mk,v 1.10 2025/03/05 03:40:03 pho Exp $

BUILDLINK_TREE+=	hs-skylighting-format-blaze-html

.if !defined(HS_SKYLIGHTING_FORMAT_BLAZE_HTML_BUILDLINK3_MK)
HS_SKYLIGHTING_FORMAT_BLAZE_HTML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-skylighting-format-blaze-html+=	hs-skylighting-format-blaze-html>=0.1.1
BUILDLINK_ABI_DEPENDS.hs-skylighting-format-blaze-html+=	hs-skylighting-format-blaze-html>=0.1.1.3nb2
BUILDLINK_PKGSRCDIR.hs-skylighting-format-blaze-html?=		../../textproc/hs-skylighting-format-blaze-html

.include "../../textproc/hs-blaze-html/buildlink3.mk"
.include "../../textproc/hs-skylighting-core/buildlink3.mk"
.endif	# HS_SKYLIGHTING_FORMAT_BLAZE_HTML_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-skylighting-format-blaze-html
