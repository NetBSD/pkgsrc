# $NetBSD: options.mk,v 1.1 2020/03/19 11:23:53 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.glfw

.include "../../mk/bsd.fast.prefs.mk"

PKG_OPTIONS_REQUIRED_GROUPS=	context
# wayland currently broken...
#PKG_OPTIONS_GROUP.context=	osmesa wayland x11
PKG_OPTIONS_GROUP.context=	osmesa x11
PKG_SUGGESTED_OPTIONS=		x11

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mosmesa)
CMAKE_ARGS+=	-DGLFW_USE_OSMESA=ON
.endif

.if !empty(PKG_OPTIONS:Mwayland)
CMAKE_ARGS+=	-DGLFW_USE_WAYLAND=ON
.  include "../../devel/wayland/buildlink3.mk"
.  include "../../devel/wayland-protocols/buildlink3.mk"
.  include "../../x11/libxkbcommon/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mx11)
.  include "../../x11/libICE/buildlink3.mk"
.  include "../../x11/libXcursor/buildlink3.mk"
.  include "../../x11/libXi/buildlink3.mk"
.  include "../../x11/libXinerama/buildlink3.mk"
.  include "../../x11/libXrandr/buildlink3.mk"
.  include "../../x11/libXxf86vm/buildlink3.mk"
.  include "../../x11/libxkbcommon/buildlink3.mk"
.endif
