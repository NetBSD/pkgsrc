# $NetBSD: options.mk,v 1.1 2019/01/04 01:43:20 tnn Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.MesaDemos
PKG_SUPPORTED_OPTIONS=		egl
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	egl

.if !empty(PKG_OPTIONS:Megl)
CONFIGURE_ARGS+=	--enable-egl
PLIST.egl=		yes
.else
CONFIGURE_ARGS+=	--disable-egl
.endif
