# $NetBSD: options.mk,v 1.1.1.1 2008/09/07 22:43:00 jmcneill Exp $
#
PKG_OPTIONS_VAR=	PKG_OPTIONS.cheese
PKG_SUPPORTED_OPTIONS=	hal

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mhal)
CONFIGURE_ARGS+=	--enable-hal
# XXX FIXME
#.  include "../../sysutils/hal/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--enable-hal=no
.endif
