# $NetBSD: Makefile,v 1.1.1.1 2004/10/31 19:30:30 jdolecek Exp $

MODNAME=		ldap
PKGREVISION=		# empty
CATEGORIES+=		databases
COMMENT=		PHP extension for LDAP database access

USE_BUILDLINK3=		YES

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.openldap}

.include "../../lang/php/ext.mk"
.include "../../databases/openldap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
