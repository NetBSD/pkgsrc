# $NetBSD: options.mk,v 1.2 2012/08/29 19:56:47 drochner Exp $

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
.include "../../mk/omf-scrollkeeper.mk"
PLIST.gnome=		yes
.endif
