# $NetBSD: options.mk,v 1.3 2019/08/27 08:12:01 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.dhcp
PKG_SUPPORTED_OPTIONS+=	inet6 ldap
PKG_SUGGESTED_OPTIONS=	inet6

.include "../../mk/bsd.options.mk"

###
### Enable ipv6 support
###
.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-dhcpv6
.else
CONFIGURE_ARGS+=	--disable-dhcpv6
.endif

.if !empty(PKG_OPTIONS:Mldap)
CONFIGURE_ARGS+=	--with-ldap
CONFIGURE_ARGS+=	--with-ldapcrypto
.include "../../databases/openldap-client/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-ldap
.endif
