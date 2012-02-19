# $NetBSD: buildlink3.mk,v 1.1 2012/02/19 20:07:42 gls Exp $

BUILDLINK_TREE+=	ffmpegthumbnailer

.if !defined(FFMPEGTHUMBNAILER_BUILDLINK3_MK)
FFMPEGTHUMBNAILER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ffmpegthumbnailer+=	ffmpegthumbnailer>=2.0.6nb1
BUILDLINK_PKGSRCDIR.ffmpegthumbnailer?=	../../multimedia/ffmpegthumbnailer

#.include "../../graphics/png/buildlink3.mk"
#.include "../../multimedia/ffmpeg/buildlink3.mk"
.endif	# FFMPEGTHUMBNAILER_BUILDLINK3_MK

BUILDLINK_TREE+=	-ffmpegthumbnailer
