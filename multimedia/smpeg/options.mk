# $NetBSD: options.mk,v 1.4 2019/11/23 23:03:01 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.smpeg
PKG_SUPPORTED_OPTIONS=	opengl-player

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		gtk opengl

.if !empty(PKG_OPTIONS:Mopengl-player)
PLIST.opengl=		yes
CONFIGURE_ARGS+=	--enable-opengl-player
.  include "../../graphics/glu/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-opengl-player
.endif
