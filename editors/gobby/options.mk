# $NetBSD: options.mk,v 1.1 2008/05/22 17:39:50 tnn Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gobby
PKG_SUPPORTED_OPTIONS=	gnome
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		gnome
.if !empty(PKG_OPTIONS:Mgnome)
.include "../../sysutils/gnome-vfs/buildlink3.mk"
PLIST.gnome=		yes
CONFIGURE_ARGS+=	--with-gnome
.endif
