# $NetBSD: options.mk,v 1.24 2026/05/15 17:00:56 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.pango
PKG_SUPPORTED_OPTIONS=	introspection libthai x11
PKG_SUGGESTED_OPTIONS=	x11

PKG_SUGGESTED_OPTIONS+=	${${USE_CROSS_COMPILE:tl} == "yes":?:introspection}

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	introspection
PLIST_VARS+=	x11

###
### X11 support
###
.if !empty(PKG_OPTIONS:Mx11)
# fix for pangox.pc
PLIST.x11=	yes
MESON_ARGS+=	-Dxft=enabled
BUILDLINK_API_DEPENDS.Xft2+=	Xft2>=2.1.7nb3
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
BUILDLINK_DEPMETHOD.libXt?=	build # only for configure
.include "../../x11/libXt/buildlink3.mk"
.else
MESON_ARGS+=	-Dxft=disabled
.endif

###
### gobject-introspection
###
.if !empty(PKG_OPTIONS:Mintrospection)
PLIST.introspection=	yes
MESON_ARGS+=	-Dintrospection=enabled
TOOL_DEPENDS+=	glib2-introspection-[0-9]*:../../devel/glib2-introspection
BUILDLINK_DEPMETHOD.gobject-introspection=	build
BUILDLINK_API_DEPENDS.gobject-introspection+=	gobject-introspection>=1.84.0
.include "../../devel/gobject-introspection/buildlink3.mk"
.else
MESON_ARGS+=	-Dintrospection=disabled
.endif

###
### Thai language support
###
.if !empty(PKG_OPTIONS:Mlibthai)
MESON_ARGS+=	-Dlibthai=enabled
.include "../../devel/libthai/buildlink3.mk"
.else
MESON_ARGS+=	-Dlibthai=disabled
.endif

.include "../../mk/bsd.prefs.mk"
