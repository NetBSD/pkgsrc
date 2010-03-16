# $NetBSD: Makefile,v 1.14 2010/03/16 11:54:31 taca Exp $

MODNAME=		pdo_pgsql
CATEGORIES+=		databases
COMMENT=		PHP extension for PHP Data Objects (PostgreSQL)

PKG_DESTDIR_SUPPORT=	user-destdir
USE_PHP_EXT_PATCHES=	yes

.include "../../mk/bsd.prefs.mk"

.include "../../lang/php/ext.mk"

CONFIGURE_ARGS+=	--with-${MODNAME}
CONFIGURE_ARGS+=	--with-${PKGMODNAME}=shared,${PGSQL_PREFIX}

.include "../../mk/pgsql.buildlink3.mk"
.include "../../databases/php-pdo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
