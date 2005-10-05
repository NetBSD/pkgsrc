# $NetBSD: options.mk,v 1.2 2005/10/05 13:29:49 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.bitchx
PKG_SUPPORTED_OPTIONS=	gtk

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
