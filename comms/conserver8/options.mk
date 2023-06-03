# $NetBSD: options.mk,v 1.7 2023/06/03 01:05:47 riastradh Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.conserver8

PKG_OPTIONS_OPTIONAL_GROUPS=	connectivity
PKG_OPTIONS_GROUP.connectivity=	inet6 uds

PKG_SUPPORTED_OPTIONS=	gssapi pam ssl

PKG_SUGGESTED_OPTIONS=	ssl

# The BSDs require separate inet6 & inet sockets,
# and conserver8 doesn't have code to do that as of 8.2.1
.if ${OPSYS} != "NetBSD" && ${OPSYS} != "FreeBSD" && ${OPSYS} != "OpenBSD" && ${OPSYS} != "DragonFly"
PKG_SUGGESTED_OPTIONS+=	inet6
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgssapi)
.  include "../../mk/krb5.buildlink3.mk"
CONFIGURE_ARGS+=	--with-gssapi
.endif

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
.  include "../../security/openssl/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-openssl
.endif
