# $NetBSD: buildlink3.mk,v 1.1 2023/11/12 21:28:04 nia Exp $

BUILDLINK_TREE+=	SDL2

.if !defined(SDL2_BUILDLINK3_MK)
SDL2_BUILDLINK3_MK:=

BUILDLINK_ABI_DEPENDS.SDL2+=	SDL2>=2.0.3
BUILDLINK_API_DEPENDS.SDL2+=	SDL2>=2.0.3<2.1.0
BUILDLINK_PKGSRCDIR.SDL2?=	../../devel/SDL2-legacy-darwin
BUILDLINK_INCDIRS.SDL2+=	include/SDL2

pkgbase := SDL2
.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.SDL2:Malsa}
.include "../../audio/alsa-lib/buildlink3.mk"
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

.if ${PKG_BUILD_OPTIONS.SDL2:Mx11}
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.endif

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.endif	# SDL2_BUILDLINK3_MK

BUILDLINK_TREE+=	-SDL2
