# $NetBSD: options.mk,v 1.2 2004/11/17 19:56:49 xtraeme Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.balsa2
PKG_SUPPORTED_OPTIONS=	openldap ssl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mopenldap)
CONFIGURE_ARGS+=        --with-ldap
.  include "../../databases/openldap/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mssl)
CONFIGURE_ARGS+=	--with-ssl=${BUILDLINK_PREFIX.openssl}
.  include "../../security/openssl/buildlink3.mk"
.endif
