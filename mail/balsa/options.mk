# $NetBSD: options.mk,v 1.1 2007/09/20 20:50:50 wiz Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.balsa
PKG_SUPPORTED_OPTIONS=	ldap ssl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mldap)
CONFIGURE_ARGS+=	--with-ldap
.  include "../../databases/openldap-client/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mssl)
CONFIGURE_ARGS+=	--with-ssl=${BUILDLINK_PREFIX.openssl}
.  include "../../security/openssl/buildlink3.mk"
.endif
