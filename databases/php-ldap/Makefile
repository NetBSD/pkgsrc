# $NetBSD: Makefile,v 1.2 2004/10/31 21:07:14 jdolecek Exp $

MODNAME=		ldap
PKGREVISION=		# empty
CATEGORIES+=		databases
COMMENT=		PHP extension for LDAP database access

USE_BUILDLINK3=		YES

.include "../../lang/php/ext.mk"

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.openldap}

.include "../../databases/openldap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
