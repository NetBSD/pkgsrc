# $NetBSD: Makefile,v 1.12 2004/04/20 19:19:23 jdolecek Exp $

MODNAME=		ldap
PKGREVISION=		# empty
CATEGORIES+=		databases
COMMENT=		PHP4 extension for LDAP database access

USE_BUILDLINK2=		YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.openldap}

.include "../../databases/openldap/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
