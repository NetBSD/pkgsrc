# $NetBSD: options.mk,v 1.1 2004/11/14 17:02:03 jmmv Exp $
#

.if defined(USE_OPENLDAP) && ${USE_OPENLDAP} == YES
PKG_DEFAULT_OPTIONS+=	openldap
.endif

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
