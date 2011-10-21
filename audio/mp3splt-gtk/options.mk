# $NetBSD: options.mk,v 1.1 2011/10/21 20:56:00 ryoon Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mp3splt-gtk
PKG_SUPPORTED_OPTIONS=	gnome
PKG_SUGGESTED_OPTIONS=	gnome

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		gnome
.if empty(PKG_OPTIONS:Mgnome)
CONFIGURE_ARGS+=	--disable-gnome
.else
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
PLIST.gnome=		yes
.endif
