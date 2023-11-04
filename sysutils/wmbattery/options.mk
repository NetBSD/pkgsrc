# $NetBSD: options.mk,v 1.2 2023/11/04 12:28:10 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.wmbattery
PKG_SUPPORTED_OPTIONS=	upower

.include "../../mk/bsd.options.mk"

#
# upower support
#
.if !empty(PKG_OPTIONS:Mupower)
CONFIGURE_ARGS+=	--enable-upower
.include "../../sysutils/hal/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-upower
.endif
