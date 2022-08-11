# $NetBSD: buildlink3.mk,v 1.22 2022/08/11 05:08:02 gutteridge Exp $

BUILDLINK_TREE+=	fluidsynth

.if !defined(FLUIDSYNTH_BUILDLINK3_MK)
FLUIDSYNTH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fluidsynth+=	fluidsynth>=1.0.5
BUILDLINK_ABI_DEPENDS.fluidsynth+=	fluidsynth>=2.2.8nb1
BUILDLINK_PKGSRCDIR.fluidsynth?=	../../audio/fluidsynth

pkgbase := fluidsynth
.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.fluidsynth:Malsa}
.  include "../../audio/alsa-lib/buildlink3.mk"
.endif
.if ${PKG_BUILD_OPTIONS.fluidsynth:Mdbus}
.  include "../../sysutils/dbus/buildlink3.mk"
.endif
.if ${PKG_BUILD_OPTIONS.fluidsynth:Mjack}
.  include "../../audio/jack/buildlink3.mk"
.endif
.if ${PKG_BUILD_OPTIONS.fluidsynth:Mladspa}
.  include "../../audio/ladspa/buildlink3.mk"
.endif
.if ${PKG_BUILD_OPTIONS.fluidsynth:Mportaudio}
.  include "../../audio/portaudio/buildlink3.mk"
.endif
.if ${PKG_BUILD_OPTIONS.fluidsynth:Mpulseaudio}
.  include "../../audio/pulseaudio/buildlink3.mk"
.endif
.if ${PKG_BUILD_OPTIONS.fluidsynth:Msdl2}
.  include "../../devel/SDL2/buildlink3.mk"
.endif
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.endif # FLUIDSYNTH_BUILDLINK3_MK

BUILDLINK_TREE+=	-fluidsynth
