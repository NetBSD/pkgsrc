# $NetBSD: options.mk,v 1.2 2008/12/20 20:52:27 reed Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.evince
PKG_SUPPORTED_OPTIONS=	dvi djvu gnome
PKG_SUGGESTED_OPTIONS=	gnome

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		${PKG_SUPPORTED_OPTIONS}

.if !empty(PKG_OPTIONS:Mdvi)
CONFIGURE_ARGS+=	--enable-dvi
PLIST.dvi=		yes
GCONF_SCHEMAS+=	evince-thumbnailer-dvi.schemas
.include "../../mk/tex.buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mdjvu)
CONFIGURE_ARGS+=	--enable-djvu
PLIST.djvu=		yes
GCONF_SCHEMAS+=	evince-thumbnailer-djvu.schemas
.include "../../graphics/djvulibre-lib/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mgnome)
COMMENT+=		for the GNOME Desktop
BUILDLINK_API_DEPENDS.libgnomeui+=	libgnomeui>=2.14.0
.include "../../devel/libgnomeui/buildlink3.mk"
.else
COMMENT+=		(GTK version)
CONFIGURE_ARGS+=	--without-libgnome --disable-nautilus
.endif

