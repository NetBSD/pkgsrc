# $NetBSD: options.mk,v 1.2 2021/03/12 09:57:18 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.chrony
PKG_SUPPORTED_OPTIONS=		gnutls
PKG_SUGGESTED_OPTIONS=		gnutls
PKG_OPTIONS_LEGACY_OPTS+=	nettle:gnutls

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgnutls)
USE_TOOLS+=	pkg-config
.include "../../security/gnutls/buildlink3.mk"
.include "../../security/nettle/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-gnutls
CONFIGURE_ARGS+=	--without-nettle
.endif
