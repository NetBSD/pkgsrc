# $NetBSD: options.mk,v 1.1 2025/04/10 16:47:52 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.SDL3
PKG_SUPPORTED_OPTIONS=		alsa dbus jack opengl libusb pulseaudio x11

# other platforms use usbhid etc
PKG_SUGGESTED_OPTIONS.Linux=	alsa libusb

.include "../../mk/bsd.fast.prefs.mk"

.if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64"
PKG_SUPPORTED_OPTIONS+=		simd
.endif

.if ${OPSYS} != "Darwin"
PKG_SUPPORTED_OPTIONS+=		libdrm
PKG_SUGGESTED_OPTIONS+=		libdrm x11
.endif

.if ${MACHINE_ARCH} == "x86_64"
PKG_SUGGESTED_OPTIONS+=		simd
.endif

.include "../../devel/wayland/platform.mk"

.if ${PLATFORM_SUPPORTS_WAYLAND} == "yes"
PKG_SUPPORTED_OPTIONS+=	wayland
PKG_SUGGESTED_OPTIONS+=	wayland
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
CMAKE_CONFIGURE_ARGS+=	-DSDL_ALSA=ON
.  include "../../audio/alsa-lib/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DSDL_ALSA=OFF
.endif

.if !empty(PKG_OPTIONS:Mdbus)
CMAKE_CONFIGURE_ARGS+=	-DSDL_DBUS=ON
.  include "../../sysutils/dbus/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DSDL_DBUS=OFF
.endif

.if !empty(PKG_OPTIONS:Mlibdrm)
CMAKE_CONFIGURE_ARGS+=	-DSDL_KMSDRM=ON
.  include "../../x11/libdrm/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DSDL_KMSDRM=OFF
.endif

.if !empty(PKG_OPTIONS:Mjack)
CMAKE_CONFIGURE_ARGS+=	-DSDL_JACK=ON
.  include "../../audio/jack/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DSDL_JACK=OFF
.endif

.if !empty(PKG_OPTIONS:Mlibusb)
CMAKE_CONFIGURE_ARGS+=	-DSDL_HIDAPI_LIBUSB=ON
.  include "../../devel/libusb/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DSDL_HIDAPI_LIBUSB=OFF
.endif

.if !empty(PKG_OPTIONS:Mopengl)
CMAKE_CONFIGURE_ARGS+=	-DSDL_OPENGL=ON
.  if ${OPSYS} != "Darwin"
.    include "../../graphics/MesaLib/buildlink3.mk"
.  endif
.else
CMAKE_CONFIGURE_ARGS+=	-DSDL_OPENGL=OFF
CMAKE_CONFIGURE_ARGS+=	-DSDL_OPENGLES=OFF
.endif

.if !empty(PKG_OPTIONS:Mpulseaudio)
CMAKE_CONFIGURE_ARGS+=	-DSDL_PULSEAUDIO=ON
.  include "../../audio/pulseaudio/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DSDL_PULSEAUDIO=OFF
.endif

.if !empty(PKG_OPTIONS:Msimd)
# if not i386 use autodetection for compiler support
.  if ${MACHINE_ARCH} == "i386"
CFLAGS+=		-march=i686 -mmmx -msse -msse2
CMAKE_CONFIGURE_ARGS+=	-DSDL_AVX=OFF
CMAKE_CONFIGURE_ARGS+=	-DSDL_AVX2=OFF
CMAKE_CONFIGURE_ARGS+=	-DSDL_AVX512F=OFF
CMAKE_CONFIGURE_ARGS+=	-DSDL_MMX=ON
CMAKE_CONFIGURE_ARGS+=	-DSDL_SSE=ON
CMAKE_CONFIGURE_ARGS+=	-DSDL_SSE=ON
CMAKE_CONFIGURE_ARGS+=	-DSDL_SSE2=ON
CMAKE_CONFIGURE_ARGS+=	-DSDL_SSE3=OFF
CMAKE_CONFIGURE_ARGS+=	-DSDL_SSE4_1=OFF
CMAKE_CONFIGURE_ARGS+=	-DSDL_SSE4_2=OFF
.  endif
.else
CMAKE_CONFIGURE_ARGS+=	-DSDL_AVX=OFF
CMAKE_CONFIGURE_ARGS+=	-DSDL_AVX2=OFF
CMAKE_CONFIGURE_ARGS+=	-DSDL_AVX512F=OFF
CMAKE_CONFIGURE_ARGS+=	-DSDL_MMX=OFF
CMAKE_CONFIGURE_ARGS+=	-DSDL_SSE=OFF
CMAKE_CONFIGURE_ARGS+=	-DSDL_SSE2=OFF
CMAKE_CONFIGURE_ARGS+=	-DSDL_SSE3=OFF
CMAKE_CONFIGURE_ARGS+=	-DSDL_SSE4_1=OFF
CMAKE_CONFIGURE_ARGS+=	-DSDL_SSE4_2=OFF
.endif

.if !empty(PKG_OPTIONS:Mwayland)
CMAKE_CONFIGURE_ARGS+=	-DSDL_WAYLAND=ON
TOOL_DEPENDS+=		${BUILDLINK_API_DEPENDS.wayland:=:../../devel/wayland}
.  include "../../devel/wayland/buildlink3.mk"
.  include "../../devel/wayland-protocols/buildlink3.mk"
.  include "../../x11/libxkbcommon/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DSDL_WAYLAND=OFF
.endif

.if !empty(PKG_OPTIONS:Mx11)
CMAKE_CONFIGURE_ARGS+=	-DSDL_X11=ON
.  include "../../x11/libXcursor/buildlink3.mk"
.  include "../../x11/libXext/buildlink3.mk"
.  include "../../x11/libXi/buildlink3.mk"
.  include "../../x11/libXfixes/buildlink3.mk"
.  include "../../x11/libXrandr/buildlink3.mk"
.  include "../../x11/libXrender/buildlink3.mk"
.  include "../../x11/libXScrnSaver/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DSDL_X11=OFF
.endif
