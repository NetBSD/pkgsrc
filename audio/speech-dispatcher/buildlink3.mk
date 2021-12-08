# $NetBSD: buildlink3.mk,v 1.4 2021/12/08 16:01:44 adam Exp $

BUILDLINK_TREE+=	speech-dispatcher

.if !defined(SPEECH_DISPATCHER_BUILDLINK3_MK)
SPEECH_DISPATCHER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.speech-dispatcher+=	speech-dispatcher>=0.8.4
BUILDLINK_ABI_DEPENDS.speech-dispatcher?=		speech-dispatcher>=0.10.2nb2
BUILDLINK_PKGSRCDIR.speech-dispatcher?=		../../audio/speech-dispatcher

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.endif	# SPEECH_DISPATCHER_BUILDLINK3_MK

BUILDLINK_TREE+=	-speech-dispatcher
