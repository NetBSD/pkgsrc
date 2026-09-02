# $NetBSD: buildlink3.mk,v 1.10 2026/09/02 19:01:00 wiz Exp $

BUILDLINK_TREE+=	speech-dispatcher

.if !defined(SPEECH_DISPATCHER_BUILDLINK3_MK)
SPEECH_DISPATCHER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.speech-dispatcher+=	speech-dispatcher>=0.8.4
BUILDLINK_ABI_DEPENDS.speech-dispatcher+=	speech-dispatcher>=0.12.1nb4
BUILDLINK_PKGSRCDIR.speech-dispatcher?=		../../audio/speech-dispatcher

.include "../../devel/glib2/buildlink3.mk"
.endif	# SPEECH_DISPATCHER_BUILDLINK3_MK

BUILDLINK_TREE+=	-speech-dispatcher
