# $NetBSD: options.mk,v 1.2 2009/07/22 15:59:50 manu Exp $

PKG_OPTIONS_VAR=        PKG_OPTIONS.php-ldap
PKG_SUPPORTED_OPTIONS=  sasl exop

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msasl)
USE_BUILTIN.openldap-client=no
.  include "../../databases/openldap-client/builtin.mk"
.  include "../../databases/openldap-client/buildlink3.mk"
.  include "../../security/cyrus-sasl/buildlink3.mk"
CONFIGURE_ARGS+= --with-ldap-sasl=${PREFIX}
.endif

.if !empty(PKG_OPTIONS:Mexop)
EXOP_PATCH=	${FILESDIR}/ldap-ctrl-exop.patch
post-patch:
	${PATCH} -d ${WRKSRC} -p2 --forward --quiet  < ${EXOP_PATCH}
.endif
