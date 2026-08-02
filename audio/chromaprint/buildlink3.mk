# $NetBSD: buildlink3.mk,v 1.13 2026/08/02 01:43:28 adam Exp $

BUILDLINK_TREE+=	chromaprint

.if !defined(CHROMAPRINT_BUILDLINK3_MK)
CHROMAPRINT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.chromaprint+=	chromaprint>=1.1
BUILDLINK_ABI_DEPENDS.chromaprint+=	chromaprint>=1.4.3nb3
BUILDLINK_PKGSRCDIR.chromaprint?=	../../audio/chromaprint
.endif	# CHROMAPRINT_BUILDLINK3_MK

BUILDLINK_TREE+=	-chromaprint
