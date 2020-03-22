# $NetBSD: buildlink3.mk,v 1.12 2020/03/22 07:34:03 nia Exp $

BUILDLINK_TREE+=	chromaprint

.if !defined(CHROMAPRINT_BUILDLINK3_MK)
CHROMAPRINT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.chromaprint+=	chromaprint>=1.1
BUILDLINK_ABI_DEPENDS.chromaprint?=	chromaprint>=1.4.3nb3
BUILDLINK_PKGSRCDIR.chromaprint?=	../../audio/chromaprint
.endif	# CHROMAPRINT_BUILDLINK3_MK

BUILDLINK_TREE+=	-chromaprint
