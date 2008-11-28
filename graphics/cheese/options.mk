# $NetBSD: options.mk,v 1.2 2008/11/28 14:29:31 jmcneill Exp $
#
PKG_OPTIONS_VAR=	PKG_OPTIONS.cheese
PKG_SUPPORTED_OPTIONS=	hal
PKG_SUGGESTED_OPTIONS=	hal

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mhal)
CONFIGURE_ARGS+=	--enable-hal
.include "../../sysutils/hal/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--enable-hal=no
.endif
