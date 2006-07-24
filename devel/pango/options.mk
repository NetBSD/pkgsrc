# $NetBSD: options.mk,v 1.2 2006/07/24 23:20:50 minskim Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.pango
PKG_SUPPORTED_OPTIONS=	x11
PKG_SUGGESTED_OPTIONS=	x11

.include "../../mk/bsd.options.mk"

###
### X11 support
###
.if !empty(PKG_OPTIONS:Mx11)
# Force not to build the atsui module, because it causes the xlib backend
# of cairo to crash.
CONFIGURE_ENV+=	ac_cv_lib_cairo_cairo_atsui_font_face_create_for_atsu_font_id=no
PLIST_SUBST+=		CARBON="@comment "
PLIST_SUBST+=		X11=""
BUILDLINK_API_DEPENDS.Xrender+=	Xrender>=0.8
.include "../../fonts/Xft2/buildlink3.mk"
.include "../../x11/Xrender/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-x
PLIST_SUBST+=		X11="@comment "
.if exists(/System/Library/Frameworks/Carbon.framework)
PLIST_SUBST+=		CARBON=
.else
PLIST_SUBST+=		CARBON="@comment "
.endif
.endif
