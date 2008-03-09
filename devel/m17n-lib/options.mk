# $NetBSD: options.mk,v 1.2 2008/03/09 11:17:27 hira Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.m17n-lib
PKG_SUPPORTED_OPTIONS=	anthy x11 libthai
PKG_SUGGESTED_OPTIONS=	x11

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Manthy)
.include "../../inputmethod/anthy/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mx11)
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/gd/buildlink3.mk"
.include "../../graphics/libotf/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../mk/xaw.buildlink3.mk"
PLIST_SUBST+=	X11=""
.else
CONFIGURE_ARGS+=	--without-gui
PLIST_SUBST+=	X11="@comment "
.endif

.if !empty(PKG_OPTIONS:Mlibthai)
.include "../../devel/libthai/buildlink3.mk"
.endif
