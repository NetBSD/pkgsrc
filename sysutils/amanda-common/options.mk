# $NetBSD: options.mk,v 1.2 2012/05/20 11:13:35 sbd Exp $

# Since amanda's ipv6 usage is broken, turn it off by default.

PKG_OPTIONS_VAR=	PKG_OPTIONS.amanda
PKG_SUPPORTED_OPTIONS=	inet6 amanda-fqdn amanda-ssh
PKG_SUGGESTED_OPTIONS=	amanda-ssh

PKG_OPTIONS_LEGACY_VARS+=	AMANDA_FQDN:amanda-fqdn
PKG_OPTIONS_LEGACY_VARS+=	AMANDA_SSH:amanda-ssh

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--with-ipv6
.else
CONFIGURE_ARGS+=	--without-ipv6
.endif

.if !empty(PKG_OPTIONS:Mamanda-fqdn)
CONFIGURE_ARGS+=        --with-fqdn
.endif

.if !empty(PKG_OPTIONS:Mamanda-ssh)
CONFIGURE_ARGS+=        --with-ssh-security
.endif
