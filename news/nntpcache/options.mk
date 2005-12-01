# $NetBSD: options.mk,v 1.1 2005/12/01 20:10:41 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.nntpcache
PKG_SUPPORTED_OPTIONS=	nntpcache-pgp
# compile error:
# authinfo_ldap.c: In function `ldap_got_pass':
# authinfo_ldap.c:81: error: dereferencing pointer to incomplete type
# authinfo_ldap.c:47: warning: unused variable `dom'
# PKG_SUPPORTED_OPTIONS+=	openldap
# remove after 2005Q4
PKG_OPTIONS_LEGACY_VARS+=	NNTP_USE_PGP:nntpcache-pgp

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mnntpcache-pgp)
DEPENDS+=		pgp-2.*:../../security/pgp2
.endif

.if !empty(PKG_OPTIONS:Mopenldap)
CONFIGURE_ARGS+=	--with-authinfo-ldap
.include "../../databases/openldap/buildlink3.mk"
.endif
