# $NetBSD: buildlink3.mk,v 1.1 2014/04/30 14:09:54 wiz Exp $

BUILDLINK_TREE+=	chromaprint

.if !defined(CHROMAPRINT_BUILDLINK3_MK)
CHROMAPRINT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.chromaprint+=	chromaprint>=1.1
BUILDLINK_PKGSRCDIR.chromaprint?=	../../audio/chromaprint

#.include "../../multimedia/ffmpeg/buildlink3.mk"
.endif	# CHROMAPRINT_BUILDLINK3_MK

BUILDLINK_TREE+=	-chromaprint
