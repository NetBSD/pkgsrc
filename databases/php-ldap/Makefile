# $NetBSD: Makefile,v 1.24.10.1 2015/05/20 20:42:57 tron Exp $

MODNAME=		ldap
CATEGORIES+=		databases
COMMENT=		PHP extension for LDAP database access

CONFLICTS=	php-ldap-[0-9]*

USE_PHP_EXT_PATCHES=	yes

.include "options.mk"

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.openldap-client}

.include "../../lang/php/ext.mk"
.include "../../databases/openldap-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
