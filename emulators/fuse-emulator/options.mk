# $NetBSD: options.mk,v 1.2 2017/05/26 19:35:48 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.fuse
PKG_SUPPORTED_OPTIONS=	gtk sdl
PKG_SUGGESTED_OPTIONS=	gtk

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		gtk sdl

.if !empty(PKG_OPTIONS:Mgtk)
CONFIGURE_ARGS+=	--with-gtk3
PLIST.gtk=		yes
.include "../../x11/gtk3/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Msdl)
CONFIGURE_ARGS+=	--with-sdl
PLIST.sdl=		yes
.include "../../devel/SDL/buildlink3.mk"
.endif
