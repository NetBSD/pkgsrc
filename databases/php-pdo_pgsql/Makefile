# $NetBSD: Makefile,v 1.17 2012/10/02 21:25:39 asau Exp $

MODNAME=		pdo_pgsql
CATEGORIES+=		databases
COMMENT=		PHP extension for PHP Data Objects (PostgreSQL)

USE_PHP_EXT_PATCHES=	yes

.include "../../mk/bsd.prefs.mk"

.include "../../lang/php/ext.mk"

CONFIGURE_ARGS+=	--with-${MODNAME}
CONFIGURE_ARGS+=	--with-${PKGMODNAME}=shared,${PGSQL_PREFIX}

.include "../../mk/pgsql.buildlink3.mk"
.include "../../databases/php-pdo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
