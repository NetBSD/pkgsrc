# $NetBSD: options.mk,v 1.6 2026/08/08 06:40:46 adam Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.fuse
PKG_SUPPORTED_OPTIONS=		# empty
PKG_OPTIONS_OPTIONAL_GROUPS=	gui
PKG_OPTIONS_GROUP.gui=		gtk sdl
PKG_SUGGESTED_OPTIONS=		gtk

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		sdl

.if !empty(PKG_OPTIONS:Mgtk)
.include "../../x11/gtk3/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-gtk
.endif

.if !empty(PKG_OPTIONS:Msdl)
CONFIGURE_ARGS+=	--with-sdl
PLIST.sdl=		yes
.endif
