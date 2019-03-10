# $NetBSD: options.mk,v 1.1 2019/03/10 19:16:46 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.chrony
PKG_SUPPORTED_OPTIONS=	nettle
PKG_SUGGESTED_OPTIONS=	nettle

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mnettle)
USE_TOOLS+=	pkg-config
.include "../../security/nettle/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-nettle
.endif
