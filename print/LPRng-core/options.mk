# $NetBSD: options.mk,v 1.1 2005/06/01 18:51:57 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.LPRng-core
PKG_SUPPORTED_OPTIONS=	lprng-priv-ports lprng-suid
PKG_SUGGESTED_OPTIONS=	lprng-suid
PKG_OPTIONS_LEGACY_VARS+=	LPRNG_PRIV_PORTS:lprng-priv-ports
PKG_OPTIONS_LEGACY_VARS+=	LPRNG_SUID:lprng-suid

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlprng-priv-ports)
CONFIGURE_ARGS+=	--enable-priv_ports
.endif
.if empty(PKG_OPTIONS:Mlprng-suid)
CONFIGURE_ARGS+=	--disable-setuid
.endif
