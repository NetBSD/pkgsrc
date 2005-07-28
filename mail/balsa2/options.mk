# $NetBSD: options.mk,v 1.3 2005/07/28 14:58:36 wiz Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.balsa2
PKG_SUPPORTED_OPTIONS=	ldap ssl
# remove after 2005Q3
PKG_OPTIONS_LEGACY_OPTS+= openldap:ldap

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mldap)
CONFIGURE_ARGS+=        --with-ldap
.  include "../../databases/openldap/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mssl)
CONFIGURE_ARGS+=	--with-ssl=${BUILDLINK_PREFIX.openssl}
.  include "../../security/openssl/buildlink3.mk"
.endif
