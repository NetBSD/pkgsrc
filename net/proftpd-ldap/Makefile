# $NetBSD: Makefile,v 1.3 2016/03/14 22:47:10 wiedi Exp $

.include "../../net/proftpd/Makefile.module"

PROFTPD_MOD=	ldap
PKGNAME=	${DISTNAME:S/proftpd/proftpd-${PROFTPD_MOD}/}
COMMENT=	LDAP module for ProFTPD

CONFIGURE_ARGS+=	--with-shared=mod_ldap:mod_quotatab_ldap

.include "../../databases/openldap-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
