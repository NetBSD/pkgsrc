# $NetBSD: buildlink3.mk,v 1.7 2015/06/04 20:07:57 szptvlfn Exp $

BUILDLINK_TREE+=	hs-text

.if !defined(HS_TEXT_BUILDLINK3_MK)
HS_TEXT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-text+=	hs-text>=1.2.1
BUILDLINK_ABI_DEPENDS.hs-text+=	hs-text>=1.2.1.1
BUILDLINK_PKGSRCDIR.hs-text?=	../../devel/hs-text
.endif	# HS_TEXT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-text
