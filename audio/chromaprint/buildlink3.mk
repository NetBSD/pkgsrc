# $NetBSD: buildlink3.mk,v 1.2 2014/08/11 23:09:44 wiz Exp $

BUILDLINK_TREE+=	chromaprint

.if !defined(CHROMAPRINT_BUILDLINK3_MK)
CHROMAPRINT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.chromaprint+=	chromaprint>=1.1
BUILDLINK_PKGSRCDIR.chromaprint?=	../../audio/chromaprint

#.include "../../multimedia/ffmpeg1/buildlink3.mk"
.endif	# CHROMAPRINT_BUILDLINK3_MK

BUILDLINK_TREE+=	-chromaprint
