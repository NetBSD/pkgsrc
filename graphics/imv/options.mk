# $NetBSD: options.mk,v 1.3 2021/02/03 10:43:42 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.imv
PKG_SUPPORTED_OPTIONS=		svg

PKG_OPTIONS_NONEMPTY_SETS=	display
PKG_OPTIONS_SET.display=	wayland x11

.include "../../devel/wayland/platform.mk"
.if ${PLATFORM_SUPPORTS_WAYLAND} == "yes"
PKG_SUGGESTED_OPTIONS=	svg wayland x11
.else
PKG_SUGGESTED_OPTIONS=	svg x11
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msvg)
.  include "../../graphics/librsvg/buildlink3.mk"
MESON_ARGS+=		-Dlibrsvg=enabled
.else
MESON_ARGS+=		-Dlibrsvg=disabled
.endif

PLIST_VARS+=		all
.if !empty(PKG_OPTIONS:Mwayland) && !empty(PKG_OPTIONS:Mx11)
PLIST.all=		yes
MESON_ARGS+=		-Dwindows=all
.elif !empty(PKG_OPTIONS:Mwayland)
MESON_ARGS+=		-Dwindows=wayland
.elif !empty(PKG_OPTIONS:Mx11)
MESON_ARGS+=		-Dwindows=x11
.endif

.if !empty(PKG_OPTIONS:Mwayland)
.  include "../../devel/wayland/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mx11)
.  include "../../graphics/glu/buildlink3.mk"
.  include "../../x11/libxcb/buildlink3.mk"
.  include "../../x11/libX11/buildlink3.mk"
.endif
