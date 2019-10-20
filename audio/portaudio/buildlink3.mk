# $NetBSD: buildlink3.mk,v 1.13 2019/10/20 11:10:49 nia Exp $

BUILDLINK_TREE+=	portaudio

.if !defined(PORTAUDIO_BUILDLINK3_MK)
PORTAUDIO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.portaudio+=	portaudio>=19
BUILDLINK_PKGSRCDIR.portaudio?=		../../audio/portaudio
BUILDLINK_INCDIRS.portaudio?=		include/portaudio2
BUILDLINK_LIBDIRS.portaudio+=		lib/portaudio2
BUILDLINK_CPPFLAGS.portaudio+=		-I${BUILDLINK_PREFIX.portaudio}/include/portaudio2
.endif # PORTAUDIO_BUILDLINK3_MK

BUILDLINK_TREE+=	-portaudio
