# $NetBSD: options.mk,v 1.1 2021/07/13 08:44:11 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.claws-mail
PKG_SUPPORTED_OPTIONS=	claws-mail-jpilot ldap inet6
PKG_SUGGESTED_OPTIONS=	inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mclaws-mail-jpilot)
CONFIGURE_ARGS+=	--enable-jpilot
.  include "../../comms/pilot-link-libs/buildlink3.mk"
.  include "../../comms/jpilot/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-jpilot
.endif

.if !empty(PKG_OPTIONS:Mldap)
CONFIGURE_ARGS+=	--enable-ldap
.  include "../../databases/openldap-client/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-ldap
.endif

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif
