# $NetBSD: buildlink2.mk,v 1.2 2002/12/23 01:42:08 wiz Exp $
#

.if !defined(FFMPEG_BUILDLINK2_MK)
FFMPEG_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			ffmpeg
BUILDLINK_DEPENDS.ffmpeg?=		ffmpeg>=0.4.5nb2
BUILDLINK_PKGSRCDIR.ffmpeg?=		../../graphics/ffmpeg

EVAL_PREFIX+=	BUILDLINK_PREFIX.ffmpeg=ffmpeg
BUILDLINK_PREFIX.ffmpeg_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.ffmpeg+=	include/libav/*.h
BUILDLINK_FILES.ffmpeg+=	include/libavcodec/*.h
BUILDLINK_FILES.ffmpeg+=	include/libavcodec/i386/*.h
BUILDLINK_FILES.ffmpeg+=	include/libavcodec/libac3/*.h
BUILDLINK_FILES.ffmpeg+=	lib/libav.*
BUILDLINK_FILES.ffmpeg+=	lib/libavcodec.*

BUILDLINK_TARGETS+=	ffmpeg-buildlink

ffmpeg-buildlink: _BUILDLINK_USE

.endif	# FFMPEG_BUILDLINK2_MK
