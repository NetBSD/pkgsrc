# $NetBSD: options.mk,v 1.4 2008/06/15 13:08:52 obache Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.nntpcache
PKG_SUPPORTED_OPTIONS=	nntpcache-pgp
# compile error:
# authinfo_ldap.c: In function `ldap_got_pass':
# authinfo_ldap.c:81: error: dereferencing pointer to incomplete type
# authinfo_ldap.c:47: warning: unused variable `dom'
# PKG_SUPPORTED_OPTIONS+=	openldap

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mnntpcache-pgp)
DEPENDS+=		pgp-2.*:../../security/pgp2
CONFIGURE_ENV+=		ac_cv_path_PGP=${PREFIX}/bin/pgp
.endif

.if !empty(PKG_OPTIONS:Mopenldap)
CONFIGURE_ARGS+=	--with-authinfo-ldap
.include "../../databases/openldap-client/buildlink3.mk"
.endif
