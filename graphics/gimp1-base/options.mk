# $NetBSD: options.mk,v 1.1 2005/05/31 22:26:10 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gimp-base
PKG_SUPPORTED_OPTIONS=	gimp1-helpbrowser
PKG_OPTIONS_LEGACY_VARS+=	GIMP_WITH_HELPBROWSER:gimp1-helpbrowser

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgimp1-helpbrowser)
PLIST_SUBST+=	HELPBROWSER=""
.include "../../x11/gnome-libs/buildlink3.mk"
.else
PLIST_SUBST+=	HELPBROWSER="@comment "
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.endif
