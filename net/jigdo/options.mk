# $NetBSD: options.mk,v 1.1 2026/01/03 18:13:22 bsiegert Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.jigdo
PKG_SUPPORTED_OPTIONS=	gtk
PKG_SUGGESTED_OPTIONS=	gtk

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		gtk

.if !empty(PKG_OPTIONS:Mgtk)
.  include "../../databases/db4/buildlink3.mk"
.  include "../../www/libwww/buildlink3.mk"
.  include "../../x11/gtk2/buildlink3.mk"
CONFIGURE_ARGS=		--with-gui
PLIST.gtk=		yes
.else
CONFIGURE_ARGS+=	--without-gui
.endif
