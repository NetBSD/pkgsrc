PKG_OPTIONS_VAR=	PKG_OPTIONS.suika3
PKG_SUPPORTED_OPTIONS=	opengl gstreamer jit
PKG_SUGGESTED_OPTIONS=	opengl gstreamer jit
PKG_OPTIONS_VAR=	PKG_OPTIONS.suika3

.include "../../mk/bsd.options.mk"
.include "../../mk/bsd.prefs.mk"

#
# Gstreamer support
#
.if !empty(PKG_OPTIONS:Mgstreamer)
CMAKE_CONFIGURE_ARGS+=	-DSUIKA_ENABLE_GST=ON
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DSUIKA_ENABLE_GST=OFF
.endif

#
# JIT support
#
.if !empty(PKG_OPTIONS:Mjit)
CMAKE_CONFIGURE_ARGS+=	-DSUIKA_ENABLE_JIT=ON
.else
CMAKE_CONFIGURE_ARGS+=	-DSUIKA_ENABLE_JIT=OFF
.endif

#
# OpenGL support
#

.if ${OPSYS} == "NetBSD"
.if !empty(PKG_OPTIONS:Mopengl)
CMAKE_CONFIGURE_ARGS+=	-DSUIKA_TARGET_NETBSD=ON
.include "../../graphics/MesaLib/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DSUIKA_TARGET_NETBSD_X11SOFT=ON
.endif
.endif

.if ${OPSYS} == "FreeBSD"
.if !empty(PKG_OPTIONS:Mopengl)
CMAKE_CONFIGURE_ARGS+=  -DSUIKA_TARGET_FREEBSD=ON
.else
CMAKE_CONFIGURE_ARGS+=  -DSUIKA_TARGET_FREEBSD_X11SOFT=ON
.endif
.endif

.if ${OPSYS} == "Linux"
.if !empty(PKG_OPTIONS:Mopengl)
CMAKE_CONFIGURE_ARGS+=  -DSUIKA_TARGET_LINUX=ON
.else
CMAKE_CONFIGURE_ARGS+=  -DSUIKA_TARGET_LINUX_X11SOFT=ON
.endif
.endif

# For other systems, leave it to the auto detection on CMakeLists.txt.

