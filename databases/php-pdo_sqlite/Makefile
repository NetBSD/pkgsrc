# $NetBSD: Makefile,v 1.36 2020/04/12 08:28:26 adam Exp $

MODNAME=		pdo_sqlite
CATEGORIES+=		databases
COMMENT=		PHP extension for PHP Data Objects (SQLite v3)
PKGREVISION=		3

USE_PHP_EXT_PATCHES=	yes

.include "../../lang/php/ext.mk"

CONFIGURE_ARGS+=	--with-${MODNAME}
CONFIGURE_ARGS+=	--with-${PKGMODNAME}=shared,${BUILDLINK_PREFIX.sqlite3}

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../databases/php-pdo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
