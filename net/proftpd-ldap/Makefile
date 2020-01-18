# $NetBSD: Makefile,v 1.4 2020/01/18 21:50:24 jperkin Exp $

PKGREVISION= 1
.include "../../net/proftpd/Makefile.module"

PROFTPD_MOD=	ldap
PKGNAME=	${DISTNAME:S/proftpd/proftpd-${PROFTPD_MOD}/}
COMMENT=	LDAP module for ProFTPD

CONFIGURE_ARGS+=	--with-shared=mod_ldap:mod_quotatab_ldap

.include "../../databases/openldap-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
