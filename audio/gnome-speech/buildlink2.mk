# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/12/30 17:53:27 xtraeme Exp $
#
# This Makefile fragment is included by packages that use gnome-speech.
#
# This file was created automatically using createbuildlink 2.8.
#

.if !defined(GNOME_SPEECH_BUILDLINK2_MK)
GNOME_SPEECH_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			gnome-speech
BUILDLINK_DEPENDS.gnome-speech?=		gnome-speech>=0.2.7
BUILDLINK_PKGSRCDIR.gnome-speech?=		../../audio/gnome-speech

EVAL_PREFIX+=	BUILDLINK_PREFIX.gnome-speech=gnome-speech
BUILDLINK_PREFIX.gnome-speech_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.gnome-speech+=	include/gnome-speech-1.0/gnome-speech/GNOME_Speech.h
BUILDLINK_FILES.gnome-speech+=	include/gnome-speech-1.0/gnome-speech/gnome-speech.h
BUILDLINK_FILES.gnome-speech+=	include/gnome-speech-1.0/gnome-speech/speaker.h
BUILDLINK_FILES.gnome-speech+=	lib/bonobo/servers/GNOME_Speech_SynthesisDriver_Festival.server
BUILDLINK_FILES.gnome-speech+=	lib/libgnomespeech.*
BUILDLINK_FILES.gnome-speech+=	lib/orbit-2.0/GNOME_Speech_module.*

.include "../../devel/libbonobo/buildlink2.mk"

BUILDLINK_TARGETS+=	gnome-speech-buildlink

gnome-speech-buildlink: _BUILDLINK_USE

.endif	# GNOME_SPEECH_BUILDLINK2_MK
