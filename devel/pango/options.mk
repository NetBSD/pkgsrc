# $NetBSD: options.mk,v 1.6 2008/04/12 22:43:00 jlam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.pango
PKG_SUPPORTED_OPTIONS=	x11
PKG_SUGGESTED_OPTIONS=	x11

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		x11

###
### X11 support
###
.if !empty(PKG_OPTIONS:Mx11)
# Force not to build the atsui module, because it causes the xlib backend
# of cairo to crash.
CONFIGURE_ENV+=	ac_cv_lib_cairo_cairo_atsui_font_face_create_for_atsu_font_id=no
# fix for pangox.pc
CONFIGURE_ENV+=		X_EXTRA_LIBS=${COMPILER_RPATH_FLAG}${X11BASE}/lib
PLIST.x11=		yes
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
BUILDLINK_DEPMETHOD.libXt?=	build # only for configure
.include "../../x11/libXt/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-x
.endif
