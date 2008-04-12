# $NetBSD: options.mk,v 1.6 2008/04/12 22:43:01 jlam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.dia
#PKG_SUPPORTED_OPTIONS=	gnome cairo
PKG_SUPPORTED_OPTIONS=	gnome
PKG_SUGGESTED_OPTIONS=	gnome

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		cairo gnome

.if !empty(PKG_OPTIONS:Mgnome)
USE_DIRS+=		gnome2-1.5
CONFIGURE_ARGS+=	--enable-gnome
.  include "../../devel/libgnome/buildlink3.mk"
.  include "../../devel/libgnomeui/buildlink3.mk"
PLIST.gnome=		yes
PLIST_SUBST+=		DIA_HELPDIR=share/gnome/help/dia
.else
CONFIGURE_ARGS+=	--disable-gnome
PLIST_SUBST+=		DIA_HELPDIR=share/dia/help
.endif

# Disabled, freedesktop is down.
.if !empty(PKG_OPTIONS:Mcairo)
CONFIGURE_ARGS+=	--with-cairo
.  include "../../graphics/cairo/buildlink3.mk"
PLIST.cairo=		yes
.else
CONFIGURE_ARGS+=	--without-cairo
.endif
