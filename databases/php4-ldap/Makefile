# $NetBSD: Makefile,v 1.10 2004/01/17 12:06:59 jdolecek Exp $

MODNAME=		ldap
CATEGORIES+=		databases
PKGREVISION=		1
COMMENT=		PHP4 extension for LDAP database access

USE_BUILDLINK2=		YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.openldap}

.include "../../databases/openldap/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
