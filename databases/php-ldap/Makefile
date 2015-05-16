# $NetBSD: Makefile,v 1.25 2015/05/16 11:19:52 taca Exp $

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
