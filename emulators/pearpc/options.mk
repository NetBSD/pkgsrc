# $NetBSD: options.mk,v 1.2 2007/02/19 18:44:11 joerg Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.pearpc
PKG_OPTIONS_REQUIRED_GROUPS=	ui
PKG_OPTIONS_GROUP.ui=		x11 sdl
PKG_SUGGESTED_OPTIONS=		x11

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mx11)
CONFIGURE_ARGS+=		--enable-ui=x11
.include "../../x11/libX11/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Msdl)
CONFIGURE_ARGS+=		--enable-ui=sdl
.include "../../devel/SDL/buildlink3.mk"
.endif
