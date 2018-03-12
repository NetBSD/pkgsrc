# $NetBSD: buildlink3.mk,v 1.10 2018/03/12 11:15:24 wiz Exp $

BUILDLINK_TREE+=	chromaprint

.if !defined(CHROMAPRINT_BUILDLINK3_MK)
CHROMAPRINT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.chromaprint+=	chromaprint>=1.1
BUILDLINK_ABI_DEPENDS.chromaprint?=	chromaprint>=1.4.3nb2
BUILDLINK_PKGSRCDIR.chromaprint?=	../../audio/chromaprint

.include "../../multimedia/ffmpeg3/buildlink3.mk"
.endif	# CHROMAPRINT_BUILDLINK3_MK

BUILDLINK_TREE+=	-chromaprint
