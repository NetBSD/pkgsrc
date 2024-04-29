# $NetBSD: buildlink3.mk,v 1.18 2024/04/29 02:52:29 pho Exp $

BUILDLINK_TREE+=	hs-blaze-html

.if !defined(HS_BLAZE_HTML_BUILDLINK3_MK)
HS_BLAZE_HTML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-blaze-html+=	hs-blaze-html>=0.9.2
BUILDLINK_ABI_DEPENDS.hs-blaze-html+=	hs-blaze-html>=0.9.2.0
BUILDLINK_PKGSRCDIR.hs-blaze-html?=	../../textproc/hs-blaze-html

.include "../../devel/hs-blaze-builder/buildlink3.mk"
.include "../../textproc/hs-blaze-markup/buildlink3.mk"
.endif	# HS_BLAZE_HTML_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-blaze-html
