# $NetBSD: buildlink3.mk,v 1.1 2018/09/12 19:04:07 maya Exp $

BUILDLINK_TREE+=	filter_audio

.if !defined(FILTER_AUDIO_BUILDLINK3_MK)
FILTER_AUDIO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.filter_audio+=	filter_audio>=0.0.1
BUILDLINK_PKGSRCDIR.filter_audio?=	../../audio/filter_audio
.endif	# FILTER_AUDIO_BUILDLINK3_MK

BUILDLINK_TREE+=	-filter_audio
