# $NetBSD: Makefile,v 1.12 2010/02/10 19:34:06 joerg Exp $

MODNAME=		pdo_pgsql
CATEGORIES+=		databases
COMMENT=		PHP extension for PHP Data Objects (PostgreSQL)
PKGREVISION=		1

PHP_VERSIONS_ACCEPTED=	5

PKG_DESTDIR_SUPPORT=	user-destdir
USE_PHP_EXT_PATCHES=	yes

.include "../../mk/bsd.prefs.mk"

.include "../../lang/php/ext.mk"

CONFIGURE_ARGS+=	--with-${MODNAME}
CONFIGURE_ARGS+=	--with-${PKGMODNAME}=shared,${PGSQL_PREFIX}

.include "../../mk/pgsql.buildlink3.mk"
.include "../../databases/php-pdo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
