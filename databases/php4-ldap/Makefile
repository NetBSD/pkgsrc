# $NetBSD: Makefile,v 1.7 2003/05/02 11:54:14 wiz Exp $

MODNAME=		ldap
CATEGORIES+=		databases
PKGREVISION=		1
COMMENT=		PHP4 extension for LDAP database access

USE_BUILDLINK2=		YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.openldap}
CONFIGURE_ENV+=		PTHREAD_TYPE="${PTHREAD_TYPE}"

.include "../../databases/openldap/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
