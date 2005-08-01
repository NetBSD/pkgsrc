# $NetBSD: options.mk,v 1.2 2005/08/01 11:45:56 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.tkpasman
PKG_SUPPORTED_OPTIONS=		ssl
PKG_SUGGESTED_OPTIONS=		ssl

# remove after pkgsrc-2005Q3
PKG_OPTIONS_LEGACY_VARS+=	TKPASMAN_USE_SSL:ssl

.include "../../mk/bsd.options.mk"

# SSL support
.if !empty(PKG_OPTIONS:Mssl)
.  include "../../security/openssl/buildlink3.mk"
CONFIG_SUBST+=		USE_OPENSSL="true"
CONFIG_SUBST+=		OPENSSL="${BUILDLINK_PREFIX.openssl}/bin/openssl"
.else
CONFIG_SUBST+=		USE_OPENSSL="false"
CONFIG_SUBST+=		OPENSSL=""
.endif
