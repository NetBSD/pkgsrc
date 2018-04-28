# $NetBSD: buildlink3.mk,v 1.6 2018/04/28 19:28:20 wiz Exp $

BUILDLINK_TREE+=	ffmpegthumbnailer

.if !defined(FFMPEGTHUMBNAILER_BUILDLINK3_MK)
FFMPEGTHUMBNAILER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ffmpegthumbnailer+=	ffmpegthumbnailer>=2.2.0
BUILDLINK_PKGSRCDIR.ffmpegthumbnailer?=		../../multimedia/ffmpegthumbnailer

#.include "../../graphics/png/buildlink3.mk"
#.include "../../multimedia/ffmpeg3/buildlink3.mk"
.endif	# FFMPEGTHUMBNAILER_BUILDLINK3_MK

BUILDLINK_TREE+=	-ffmpegthumbnailer
