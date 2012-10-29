# $NetBSD: Makefile,v 1.18 2012/10/29 08:50:28 manu Exp $

MODNAME=		ldap
PKGREVISION=		1
CATEGORIES+=		databases
COMMENT=		PHP extension for LDAP database access

CONFLICTS=	php-ldap-[0-9]*

USE_PHP_EXT_PATCHES=	yes

.include "options.mk"

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.openldap-client}

.include "../../lang/php/ext.mk"
.include "../../databases/openldap-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
