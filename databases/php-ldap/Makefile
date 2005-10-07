# $NetBSD: Makefile,v 1.5 2005/10/07 21:09:28 jdolecek Exp $

MODNAME=		ldap
PKGREVISION=		1
CATEGORIES+=		databases
COMMENT=		PHP extension for LDAP database access

USE_PHP_EXT_PATCHES=	yes

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.openldap}

.include "../../lang/php/ext.mk"
.include "../../databases/openldap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
