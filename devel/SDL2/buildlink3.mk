# $NetBSD: buildlink3.mk,v 1.22 2024/06/06 20:45:16 riastradh Exp $

BUILDLINK_TREE+=	SDL2

.include "../../mk/bsd.fast.prefs.mk"
.if ${MACHINE_PLATFORM:MDarwin-*-powerpc*}
# This defines SDL2_BUILDLINK3_MK.
.  include "../../devel/SDL2-legacy-darwin/buildlink3.mk"
.endif

.if !defined(SDL2_BUILDLINK3_MK)
SDL2_BUILDLINK3_MK:=

BUILDLINK_ABI_DEPENDS.SDL2+=	SDL2>=2.30.2nb1
BUILDLINK_API_DEPENDS.SDL2+=	SDL2>=2.0
BUILDLINK_PKGSRCDIR.SDL2?=	../../devel/SDL2
BUILDLINK_INCDIRS.SDL2+=	include/SDL2

.  if ${USE_CROSS_COMPILE:tl} == "yes"
# sdl2-config is a shell script that we need to run at build-time to
# learn about the target system's SDL2 toolchain options.  This is
# grody but it may not be trivial to replace by something more sensible
# like pkg-config.
TOOLS_CREATE+=		sdl2-config
TOOLS_PATH.sdl2-config=	${CROSS_DESTDIR}${LOCALBASE}/bin/sdl2-config
.  endif

pkgbase := SDL2
.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.SDL2:Malsa}
.include "../../audio/alsa-lib/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.SDL2:Mjack}
.include "../../audio/jack/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.SDL2:Mpulseaudio}
.include "../../audio/pulseaudio/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.SDL2:Mnas}
.include "../../audio/nas/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.SDL2:Mopengl} && ${OPSYS} != "Darwin"
.include "../../graphics/MesaLib/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.SDL2:Mrpi}
.include "../../misc/raspberrypi-userland/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.SDL2:Mwayland}
.include "../../devel/wayland/buildlink3.mk"
.include "../../devel/wayland-protocols/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.SDL2:Mx11}
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.endif

.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.endif	# SDL2_BUILDLINK3_MK

BUILDLINK_TREE+=	-SDL2
