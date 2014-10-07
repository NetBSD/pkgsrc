# $NetBSD: Makefile,v 1.15 2014/10/07 16:47:20 adam Exp $

MODNAME=		pdo_sqlite
PKGREVISION=		2
CATEGORIES+=		databases
COMMENT=		PHP extension for PHP Data Objects (SQLite v3)

USE_PHP_EXT_PATCHES=	yes

.include "../../mk/bsd.prefs.mk"

.include "../../lang/php/ext.mk"

CONFIGURE_ARGS+=	--with-${MODNAME}
CONFIGURE_ARGS+=	--with-${PKGMODNAME}=shared,${BUILDLINK_PREFIX.sqlite3}

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../databases/php-pdo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
