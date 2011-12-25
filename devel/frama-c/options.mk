# $NetBSD: options.mk,v 1.3 2011/12/25 15:52:12 asau Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.frama-c
PKG_SUPPORTED_OPTIONS=	gui
PKG_SUGGESTED_OPTIONS=	gui

PLIST_VARS=	gui

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgui)
PLIST.gui=	yes

.include "../../x11/gtksourceview2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--enable-gui=no
.endif
