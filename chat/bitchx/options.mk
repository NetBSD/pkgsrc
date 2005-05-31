# $NetBSD: options.mk,v 1.1 2005/05/31 16:36:40 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.bitchx
PKG_SUPPORTED_OPTIONS=	gtk
PKG_OPTIONS_LEGACY_VARS+=	BITCHX_WITH_GTK:gtk

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgtk)
.include "../../graphics/imlib/buildlink3.mk"
.include "../../x11/gnome-libs/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
CONFIGURE_ARGS+=	--with-gtk
CFLAGS+=		-I${PREFIX}/include/gnome-1.0
PLIST_SUBST+=		GTK="gtk"
PLIST_SUBST+=		NOT_GTK="@comment "
.else
PLIST_SUBST+=		GTK=
PLIST_SUBST+=		NOT_GTK=
.endif
