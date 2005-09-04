# $NetBSD: options.mk,v 1.1 2005/09/04 05:20:05 xtraeme Exp $

PKG_OPTIONS_VAR=	smpeg
PKG_SUPPORTED_OPTIONS=	gtk-player opengl-player

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgtk-player)
PLIST_SUBST+=		GTK_PLAYER=
CONFIGURE_ARGS+=	--enable-gtk-player
.  include "../../x11/gtk/buildlink3.mk"
.else
PLIST_SUBST+=		GTK_PLAYER="@comment "
CONFIGURE_ARGS+=	--disable-gtk-player --disable-gtk-test
.endif

.if !empty(PKG_OPTIONS:Mopengl-player)
PLIST_SUBST+=		OPENGL_PLAYER=
CONFIGURE_ARGS+=	--enable-opengl-player
.  include "../../graphics/glu/buildlink3.mk"
.else
PLIST_SUBST+=		OPENGL_PLAYER="@comment "
CONFIGURE_ARGS+=	--disable-opengl-player
.endif
