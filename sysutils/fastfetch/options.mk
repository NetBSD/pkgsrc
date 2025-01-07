# $NetBSD: options.mk,v 1.2 2025/01/07 20:24:32 vins Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.fastfetch
PKG_OPTIONS_OPTIONAL_GROUPS=	server
PKG_OPTIONS_GROUP.server=	wayland x11

PKG_SUPPORTED_OPTIONS=	chafa dconf dbus glib2 imagemagick libdrm libelf opencl \
			osmesa pulseaudio python sqlite3 threads wayland x11 xfce4-wm
PKG_SUGGESTED_OPTIONS=	glib2 libdrm opencl osmesa x11

CHECK_BUILTIN.pthread:= yes
.include "../../mk/pthread.builtin.mk"
CHECK_BUILTIN.pthread:= no

.if ${USE_BUILTIN.pthread:tl} == yes
PKG_SUGGESTED_OPTIONS+=	threads
.endif

.include "../../mk/bsd.options.mk"

##
## D-Bus
## Supports NetworkManager (Linux), Player & Media detection.
##
.if !empty(PKG_OPTIONS:Mdbus)
.  include "../../sysutils/dbus/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=  -DENABLE_DBUS=OFF
.endif

##
## DConf
## Needed for values that are only stored in DConf;
## (+ Fallback for GSettings)
##
.if !empty(PKG_OPTIONS:Mdconf)
.  include "../../devel/dconf/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=  -DENABLE_DCONF=OFF
.endif

##
## libchafa
## Supports image output as ascii art
##
.if !empty(PKG_OPTIONS:Mchafa)
.  include "../../graphics/chafa/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=  -DENABLE_CHAFA=OFF
.endif

##
## libdrm
## Fallback if both wayland and x11 are not available
## AMD GPU properties detection
##
.if !empty(PKG_OPTIONS:Mlibdrm)
.  include "../../x11/libdrm/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=  -DENABLE_DRM=OFF
CMAKE_CONFIGURE_ARGS+=  -DENABLE_DRM_AMDGPU=OFF
.endif

##
## libGIO
## Provides output for values that are only stored in GSettings.
##
.if !empty(PKG_OPTIONS:Mglib2)
.  include "../../devel/glib2/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=  -DENABLE_GIO=OFF
.endif

##
## libelf
## Needed for st terminal font detection.
##
.if !empty(PKG_OPTIONS:Mlibelf)
.  include "../../devel/libelf/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=  -DENABLE_ELF=OFF
.endif

##
## ImageMagick
## Supports image output using sixel or kitty graphics protocol.
##
.if !empty(PKG_OPTIONS:Mimagemagick)
.  include "../../graphics/ImageMagick/buildlink3.mk"
.  include "../../devel/zlib/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=  -DENABLE_IMAGEMAGICK6=OFF
CMAKE_CONFIGURE_ARGS+=  -DENABLE_IMAGEMAGICK7=OFF
CMAKE_CONFIGURE_ARGS+=  -DENABLE_ZLIB=OFF
.endif

##
## MesaLib
## Needed by the OpenGL module for gl context creation.
##
.if !empty(PKG_OPTIONS:Mosmesa)
.  include "../../graphics/MesaLib/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=  -DENABLE_EGL=OFF
CMAKE_CONFIGURE_ARGS+=  -DENABLE_OSMESA=OFF
.endif

##
## OpenCL
## Build OpenCL module.
##
.if !empty(PKG_OPTIONS:Mopencl)
.  include "../../parallel/ocl-icd/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=  -DENABLE_OPENCL=OFF
.endif

##
## Pulseaudio
## Provides sound device detection.
##
.if !empty(PKG_OPTIONS:Mpulseaudio)
.  include "../../audio/pulseaudio/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=  -DENABLE_PULSE=OFF
.endif

##
## Python
## Needed for zsh and fish completions.
##
.if !empty(PKG_OPTIONS:Mpython)
.  include "../../lang/python/application.mk"
.endif

##
## SQLite
## Needed for pkg (FreeBSD) & rpm package count.
##
.if !empty(PKG_OPTIONS:Msqlite3)
.  include "../../databases/sqlite3/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=  -DENABLE_SQLITE3=OFF
CMAKE_CONFIGURE_ARGS+=  -DENABLE_RPM=OFF
.endif

##
## Threads
## Enables multithreading.
##
.if !empty(PKG_OPTIONS:Mthreads)
.  include "../../mk/pthread.buildlink3.mk"
PTHREAD_AUTO_VARS=      yes
PTHREAD_OPTS+=          require
CMAKE_CONFIGURE_ARGS+=  -DENABLE_THREADS=ON
.else
CMAKE_CONFIGURE_ARGS+=  -DENABLE_THREADS=OFF
.endif

##
## Wayland
## Better display performance and output in wayland sessions.
##
.if !empty(PKG_OPTIONS:Mwayland)
.  include "../../devel/wayland/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=  -DENABLE_WAYLAND=OFF
.endif

##
## XFConf
## Needed for XFWM theme and XFCE Terminal font detection.
##
.if !empty(PKG_OPTIONS:Mxfce4-wm)
.  include "../../devel/xfce4-conf/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=  -DENABLE_XFCONF=OFF
.endif

##
## X11
## Required for display detection and faster WM detection.
##
.if !empty(PKG_OPTIONS:Mx11)
.  include "../../x11/libXrandr/buildlink3.mk"
.  include "../../x11/libxcb/buildlink3.mk"
.  include "../../x11/libX11/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=  -DENABLE_XRANDR=OFF
CMAKE_CONFIGURE_ARGS+=  -DENABLE_XCB=OFF
CMAKE_CONFIGURE_ARGS+=  -DENABLE_X11=OFF
.endif
