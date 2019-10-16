# $NetBSD: buildlink3.mk,v 1.5 2019/10/16 12:50:27 nia Exp $

BUILDLINK_TREE+=	portaudio-devel

.if !defined(PORTAUDIO_DEVEL_BUILDLINK3_MK)
PORTAUDIO_DEVEL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.portaudio-devel+=	portaudio-devel>=20060521
BUILDLINK_PKGSRCDIR.portaudio-devel?=	../../audio/portaudio-devel
BUILDLINK_INCDIRS.portaudio-devel?=	include/portaudio2
BUILDLINK_LIBDIRS.portaudio-devel+=	lib/portaudio2
BUILDLINK_CPPFLAGS.portaudio-devel+=	-I${BUILDLINK_PREFIX.portaudio-devel}/include/portaudio2
.endif # PORTAUDIO_DEVEL_BUILDLINK3_MK

BUILDLINK_TREE+=	-portaudio-devel
