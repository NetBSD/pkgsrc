# $NetBSD: buildlink3.mk,v 1.67 2020/03/08 16:49:52 wiz Exp $

BUILDLINK_TREE+=	MesaLib

.if !defined(MESALIB_BUILDLINK3_MK)
MESALIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.MesaLib+=	MesaLib>=3.4.2
BUILDLINK_ABI_DEPENDS.MesaLib+=	MesaLib>=20.0.1nb1
BUILDLINK_PKGSRCDIR.MesaLib?=	../../graphics/MesaLib

.include "../../graphics/MesaLib/features.mk"

# See <http://developer.apple.com/qa/qa2007/qa1567.html>.
.if ${X11_TYPE} == "native" && !empty(MACHINE_PLATFORM:MDarwin-[9].*-*)
BUILDLINK_LDFLAGS.MesaLib+=	-Wl,-dylib_file,/System/Library/Frameworks/OpenGL.framework/Versions/A/Libraries/libGL.dylib:/System/Library/Frameworks/OpenGL.framework/Versions/A/Libraries/libGL.dylib
.endif

pkgbase:= MesaLib

.include "../../mk/pkg-build-options.mk"

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

.if ${MESALIB_SUPPORTS_DRI} == "yes"
.  include "../../x11/libdrm/buildlink3.mk"
.endif

.include "../../mk/pthread.buildlink3.mk"
.endif # MESALIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-MesaLib
