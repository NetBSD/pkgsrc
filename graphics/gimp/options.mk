# $NetBSD: options.mk,v 1.1 2007/10/25 21:06:17 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gimp
PKG_SUPPORTED_OPTIONS=	aalib gnome
PKG_SUGGESTED_OPTIONS=	aalib gnome

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Maalib)
.include "../../graphics/aalib/buildlink3.mk"
PLIST_SUBST+=	AALIB=
.else
PLIST_SUBST+=	AALIB="@comment "
.endif

.if !empty(PKG_OPTIONS:Mgnome)
.include "../../www/libgtkhtml/buildlink3.mk"
PLIST_SUBST+=	GNOME=
.else
PLIST_SUBST+=	GNOME="@comment "
.endif
