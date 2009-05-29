# $NetBSD: options.mk,v 1.1 2009/05/29 21:23:58 manu Exp $

PKG_OPTIONS_VAR=        PKG_OPTIONS.php-ldap
PKG_SUPPORTED_OPTIONS=  sasl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msasl)
USE_BUILTIN.openldap-client=no
.  include "../../databases/openldap-client/builtin.mk"
.  include "../../databases/openldap-client/buildlink3.mk"
.  include "../../security/cyrus-sasl/buildlink3.mk"
CONFIGURE_ARGS+= --with-ldap-sasl=${PREFIX}
.endif
