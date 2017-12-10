# $NetBSD: options.mk,v 1.3 2017/12/10 15:51:04 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.fuse
PKG_SUPPORTED_OPTIONS=	gtk sdl
PKG_SUGGESTED_OPTIONS=	gtk

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		gtk sdl

.if !empty(PKG_OPTIONS:Mgtk)
PLIST.gtk=		yes
.include "../../x11/gtk3/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-gtk
.endif

.if !empty(PKG_OPTIONS:Msdl)
CONFIGURE_ARGS+=	--with-sdl
PLIST.sdl=		yes
.include "../../devel/SDL/buildlink3.mk"
.endif
