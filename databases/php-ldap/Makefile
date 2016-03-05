# $NetBSD: Makefile,v 1.26 2016/03/05 11:28:13 jperkin Exp $

MODNAME=		ldap
CATEGORIES+=		databases
COMMENT=		PHP extension for LDAP database access
PKGREVISION=		1

CONFLICTS=	php-ldap-[0-9]*

USE_PHP_EXT_PATCHES=	yes

.include "options.mk"

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.openldap-client}

.include "../../lang/php/ext.mk"
.include "../../databases/openldap-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
