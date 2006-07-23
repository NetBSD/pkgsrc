# $NetBSD: options.mk,v 1.1 2006/07/23 04:59:34 minskim Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.pango
PKG_SUPPORTED_OPTIONS=	x11
PKG_SUGGESTED_OPTIONS=	x11

.include "../../mk/bsd.options.mk"

###
### X11 support
###
.if !empty(PKG_OPTIONS:Mx11)
PLIST_SUBST+=		X11=""
BUILDLINK_API_DEPENDS.Xrender+=	Xrender>=0.8
.include "../../fonts/Xft2/buildlink3.mk"
.include "../../x11/Xrender/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-x
PLIST_SUBST+=		X11="@comment "
.endif
