# $NetBSD: buildlink3.mk,v 1.4 2014/09/13 22:03:04 szptvlfn Exp $

BUILDLINK_TREE+=	hs-text

.if !defined(HS_TEXT_BUILDLINK3_MK)
HS_TEXT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-text+=	hs-text>=1.2.0
BUILDLINK_ABI_DEPENDS.hs-text+=	hs-text>=1.2.0.0
BUILDLINK_PKGSRCDIR.hs-text?=	../../devel/hs-text
.endif	# HS_TEXT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-text
