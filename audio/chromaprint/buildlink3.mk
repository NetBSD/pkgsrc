# $NetBSD: buildlink3.mk,v 1.8 2017/01/16 23:45:10 wiz Exp $

BUILDLINK_TREE+=	chromaprint

.if !defined(CHROMAPRINT_BUILDLINK3_MK)
CHROMAPRINT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.chromaprint+=	chromaprint>=1.1
BUILDLINK_ABI_DEPENDS.chromaprint?=	chromaprint>=1.4.2nb1
BUILDLINK_PKGSRCDIR.chromaprint?=	../../audio/chromaprint

.include "../../multimedia/ffmpeg3/buildlink3.mk"
.endif	# CHROMAPRINT_BUILDLINK3_MK

BUILDLINK_TREE+=	-chromaprint
