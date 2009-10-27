# $NetBSD: options.mk,v 1.2 2009/10/27 19:47:54 drochner Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gobby
PKG_SUPPORTED_OPTIONS=	gnome
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		gnome
.if !empty(PKG_OPTIONS:Mgnome)
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
PLIST.gnome=		yes
CONFIGURE_ARGS+=	--with-gnome
.endif
