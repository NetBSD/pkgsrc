# $NetBSD: buildlink3.mk,v 1.15 2020/04/17 15:50:03 nia Exp $

BUILDLINK_TREE+=	portaudio

.if !defined(PORTAUDIO_BUILDLINK3_MK)
PORTAUDIO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.portaudio+=	portaudio>=19
BUILDLINK_PKGSRCDIR.portaudio?=		../../audio/portaudio
BUILDLINK_INCDIRS.portaudio?=		include/portaudio2
BUILDLINK_LIBDIRS.portaudio+=		lib/portaudio2
BUILDLINK_CPPFLAGS.portaudio+=		-I${BUILDLINK_PREFIX.portaudio}/include/portaudio2

pkgbase:=	portaudio

.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.portaudio:Malsa}
.  include "../../audio/alsa-lib/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.portaudio:Mjack}
.  include "../../audio/jack/buildlink3.mk"
.endif
.endif # PORTAUDIO_BUILDLINK3_MK

BUILDLINK_TREE+=	-portaudio
