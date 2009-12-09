# $NetBSD: options.mk,v 1.8 2009/12/09 10:22:04 drochner Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.dia
PKG_SUPPORTED_OPTIONS=	gnome cairo
PKG_SUGGESTED_OPTIONS=	gnome cairo

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		cairo gnome

.if !empty(PKG_OPTIONS:Mgnome)
CONFIGURE_ARGS+=	--enable-gnome
.  include "../../devel/libgnome/buildlink3.mk"
.  include "../../devel/libgnomeui/buildlink3.mk"
PLIST.gnome=		yes
PLIST_SUBST+=		DIA_HELPDIR=share/gnome/help/dia
.else
CONFIGURE_ARGS+=	--disable-gnome
PLIST_SUBST+=		DIA_HELPDIR=share/dia/help
.endif

.if !empty(PKG_OPTIONS:Mcairo)
CONFIGURE_ARGS+=	--with-cairo
.  include "../../graphics/cairo/buildlink3.mk"
PLIST.cairo=		yes
.else
CONFIGURE_ARGS+=	--without-cairo
.endif
