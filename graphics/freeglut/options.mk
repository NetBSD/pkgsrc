# $NetBSD: options.mk,v 1.1 2019/10/03 11:17:51 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.freeglut
PKG_OPTIONS_REQUIRED_GROUPS=	ui
PKG_OPTIONS_GROUP.ui=		wayland x11
PKG_SUGGESTED_OPTIONS=		x11

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mwayland)
CMAKE_ARGS+=	-DFREEGLUT_WAYLAND=ON
.include "../../devel/wayland/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mx11)
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.endif
