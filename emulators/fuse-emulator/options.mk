# $NetBSD: options.mk,v 1.1 2016/01/17 14:27:38 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.fuse
PKG_SUPPORTED_OPTIONS=	sdl gtk
PKG_SUGGESTED_OPTIONS=	gtk

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgtk)
CONFIGURE_ARGS+=	--with-gtk2
.include "../../x11/gtk2/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Msdl)
CONFIGURE_ARGS+=	--with-sdl
.include "../../devel/SDL/buildlink3.mk"
.endif
