# $NetBSD: buildlink3.mk,v 1.9 2024/05/09 01:32:41 pho Exp $

BUILDLINK_TREE+=	hs-css-text

.if !defined(HS_CSS_TEXT_BUILDLINK3_MK)
HS_CSS_TEXT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-css-text+=	hs-css-text>=0.1.3
BUILDLINK_ABI_DEPENDS.hs-css-text+=	hs-css-text>=0.1.3.0nb8
BUILDLINK_PKGSRCDIR.hs-css-text?=	../../textproc/hs-css-text

.include "../../textproc/hs-attoparsec/buildlink3.mk"
.endif	# HS_CSS_TEXT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-css-text
