# $NetBSD: buildlink3.mk,v 1.1 2025/04/10 16:47:52 nia Exp $

BUILDLINK_TREE+=	SDL3

.if !defined(SDL3_BUILDLINK3_MK)
SDL3_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.SDL3+=	SDL3>=3.0.0
BUILDLINK_PKGSRCDIR.SDL3?=	../../devel/SDL3
BUILDLINK_INCDIRS.SDL3+=	include/SDL3

pkgbase := SDL3
.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.SDL3:Malsa}
.  include "../../audio/alsa-lib/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.SDL3:Mjack}
.  include "../../audio/jack/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.SDL3:Mpulseaudio}
.  include "../../audio/pulseaudio/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.SDL3:Mopengl} && ${OPSYS} != "Darwin"
.  include "../../graphics/MesaLib/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.SDL3:Mwayland}
.  include "../../devel/wayland/buildlink3.mk"
.  include "../../devel/wayland-protocols/buildlink3.mk"
.  include "../../x11/libxkbcommon/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.SDL3:Mx11}
.  include "../../x11/libXcursor/buildlink3.mk"
.  include "../../x11/libXext/buildlink3.mk"
.  include "../../x11/libXi/buildlink3.mk"
.  include "../../x11/libXfixes/buildlink3.mk"
.  include "../../x11/libXrandr/buildlink3.mk"
.  include "../../x11/libXrender/buildlink3.mk"
.  include "../../x11/libXScrnSaver/buildlink3.mk"
.endif

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.endif	# SDL3_BUILDLINK3_MK

BUILDLINK_TREE+=	-SDL3
