# $NetBSD: buildlink3.mk,v 1.1 2020/01/19 10:24:14 pho Exp $

BUILDLINK_TREE+=	hs-css-text

.if !defined(HS_CSS_TEXT_BUILDLINK3_MK)
HS_CSS_TEXT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-css-text+=	hs-css-text>=0.1.3
BUILDLINK_ABI_DEPENDS.hs-css-text+=	hs-css-text>=0.1.3.0
BUILDLINK_PKGSRCDIR.hs-css-text?=	../../textproc/hs-css-text

.include "../../textproc/hs-attoparsec/buildlink3.mk"
.endif	# HS_CSS_TEXT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-css-text
