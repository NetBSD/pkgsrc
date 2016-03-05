# $NetBSD: Makefile,v 1.2 2016/03/05 11:29:10 jperkin Exp $

PKGREVISION= 1
.include "../../net/proftpd/Makefile.module"

PROFTPD_MOD=	ldap
PKGNAME=	${DISTNAME:S/proftpd/proftpd-${PROFTPD_MOD}/}
COMMENT=	LDAP module for ProFTPD

CONFIGURE_ARGS+=	--with-shared=mod_ldap:mod_quotatab_ldap

.include "../../databases/openldap-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
