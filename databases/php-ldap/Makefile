# $NetBSD: Makefile,v 1.14 2009/09/13 19:45:42 manu Exp $

MODNAME=		ldap
PKGREVISION=          5
CATEGORIES+=		databases
COMMENT=		PHP extension for LDAP database access

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	php-ldap-[0-9]*

USE_PHP_EXT_PATCHES=	yes

.include "options.mk"

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.openldap-client}

.include "../../lang/php/ext.mk"
.include "../../databases/openldap-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
