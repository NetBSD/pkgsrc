# $NetBSD: options.mk,v 1.2 2007/10/28 16:43:00 dogcow Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gimp
PKG_SUPPORTED_OPTIONS=	aalib gnome mng svg
PKG_SUGGESTED_OPTIONS=	aalib gnome mng svg

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

.if !empty(PKG_OPTIONS:Mmng)
.include "../../graphics/mng/buildlink3.mk"
PLIST_SUBST+=	MNG=
.else
PLIST_SUBST+=	MNG="@comment "
.endif

.if !empty(PKG_OPTIONS:Msvg)
.include "../../graphics/librsvg/buildlink3.mk"
PLIST_SUBST+=	SVG=
.else
PLIST_SUBST+=	SVG="@comment "
.endif
