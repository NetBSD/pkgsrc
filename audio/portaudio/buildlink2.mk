# $NetBSD: buildlink2.mk,v 1.2 2004/04/22 16:31:20 ben Exp $

.if !defined(PORTAUDIO_BUILDLINK2_MK)
PORTAUDIO_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		portaudio
BUILDLINK_DEPENDS.portaudio?=	portaudio>=18.1
BUILDLINK_PKGSRCDIR.portaudio?=	../../audio/portaudio

EVAL_PREFIX+=			BUILDLINK_PREFIX.portaudio=portaudio
BUILDLINK_PREFIX.portaudio_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.portaudio=	include/portaudio.h
BUILDLINK_FILES.portaudio+=	lib/libportaudio.*

BUILDLINK_TARGETS+=	portaudio-buildlink

portaudio-buildlink: _BUILDLINK_USE

.endif	# PORTAUDIO_BUILDLINK2_MK
