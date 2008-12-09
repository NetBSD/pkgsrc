# $NetBSD: options.mk,v 1.1 2008/12/09 10:36:24 ahoka Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.xfce4-thunar
PKG_SUPPORTED_OPTIONS=	hal
PKG_SUGGESTED_OPTIONS=	hal

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mhal)
.include "../../sysutils/hal/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-hal
.else
CONFIGURE_ARGS+=	--disable-hal
.endif
