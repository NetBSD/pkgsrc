# $NetBSD: buildlink3.mk,v 1.64 2019/10/21 12:30:36 nia Exp $

BUILDLINK_TREE+=	MesaLib

.if !defined(MESALIB_BUILDLINK3_MK)
MESALIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.MesaLib+=	MesaLib>=3.4.2
BUILDLINK_ABI_DEPENDS.MesaLib+=	MesaLib>=7.11.2
BUILDLINK_PKGSRCDIR.MesaLib?=	../../graphics/MesaLib

.include "../../mk/bsd.fast.prefs.mk"

# See <http://developer.apple.com/qa/qa2007/qa1567.html>.
.if ${X11_TYPE} == "native" && !empty(MACHINE_PLATFORM:MDarwin-[9].*-*)
BUILDLINK_LDFLAGS.MesaLib+=	-Wl,-dylib_file,/System/Library/Frameworks/OpenGL.framework/Versions/A/Libraries/libGL.dylib:/System/Library/Frameworks/OpenGL.framework/Versions/A/Libraries/libGL.dylib
.endif

pkgbase:= MesaLib

.if ${X11_TYPE} == "modular"
MESALIB_SUPPORTS_OSMESA=	yes
MESALIB_SUPPORTS_GLESv2=	yes
.  if ${OPSYS} != "Darwin" && ${OPSYS} != "Cygwin"
MESALIB_SUPPORTS_EGL=		yes
.  else
MESALIB_SUPPORTS_EGL=		no
.  endif
.else
.  if exists(${X11BASE}/include/EGL/egl.h)
MESALIB_SUPPORTS_EGL=		yes
.  else
MESALIB_SUPPORTS_EGL=		no
.  endif
.  if exists(${X11BASE}/lib/libOSMesa.so)
MESALIB_SUPPORTS_OSMESA=	yes
.  else
MESALIB_SUPPORTS_OSMESA=	no
.  endif
.  if exists(${X11BASE}/include/GLES2/gl2.h)
MESALIB_SUPPORTS_GLESv2=	yes
.  else
MESALIB_SUPPORTS_GLESv2=	no
.  endif
.endif

.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.MesaLib:Mwayland)
.  include "../../devel/wayland/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.MesaLib:Mx11)
.  include "../../x11/libX11/buildlink3.mk"
.  include "../../x11/libXdamage/buildlink3.mk"
.  include "../../x11/libXext/buildlink3.mk"
.  include "../../x11/libXfixes/buildlink3.mk"
.  include "../../x11/libXrandr/buildlink3.mk"
.  include "../../x11/libXxf86vm/buildlink3.mk"
.  include "../../x11/libxcb/buildlink3.mk"
.  include "../../x11/libxshmfence/buildlink3.mk"
.  include "../../x11/xcb-proto/buildlink3.mk"
.  include "../../x11/xorgproto/buildlink3.mk"
.endif

.if ${OPSYS} != "Darwin" && ${OPSYS} != "Cygwin"
.  include "../../x11/libdrm/buildlink3.mk"
.endif

.include "../../mk/pthread.buildlink3.mk"
.endif # MESALIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-MesaLib
