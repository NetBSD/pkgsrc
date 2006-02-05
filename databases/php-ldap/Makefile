# $NetBSD: Makefile,v 1.7 2006/02/05 23:08:33 joerg Exp $

MODNAME=		ldap
PKGREVISION=		3
CATEGORIES+=		databases
COMMENT=		PHP extension for LDAP database access

USE_PHP_EXT_PATCHES=	yes

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.openldap}

.include "../../lang/php/ext.mk"
.include "../../databases/openldap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
