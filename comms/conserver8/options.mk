# $NetBSD: options.mk,v 1.2 2016/03/13 18:31:11 schnoebe Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.conserver8

PKG_OPTIONS_REQUIRED_GROUPS= connectivity
PKG_OPTIONS_GROUP.connectivity=inet6 uds

PKG_SUPPORTED_OPTIONS=	pam ssl

PKG_SUGGESTED_OPTIONS=	ssl inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpam)
.  include "../../mk/pam.buildlink3.mk"
CONFIGURE_ARGS+=	--with-pam
.endif

.if !empty(PKG_OPTIONS:Muds)
CONFIGURE_ARGS+=	--with-uds
.endif

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--with-ipv6
.endif

.if !empty(PKG_OPTIONS:Mssl)
CONFIGURE_ARGS+=	--with-openssl=${SSLBASE:Q}
. include "../../security/openssl/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-openssl
.endif
