# $NetBSD: Makefile,v 1.11.2.1 2012/07/23 18:24:33 tron Exp $

MODNAME=		pdo_sqlite
CATEGORIES+=		databases
COMMENT=		PHP extension for PHP Data Objects (SQLite v3)

PKG_DESTDIR_SUPPORT=	user-destdir
USE_PHP_EXT_PATCHES=	yes

.include "../../mk/bsd.prefs.mk"

.include "../../lang/php/ext.mk"

CONFIGURE_ARGS+=	--with-${MODNAME}
CONFIGURE_ARGS+=	--with-${PKGMODNAME}=shared,${BUILDLINK_PREFIX.sqlite3}

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../databases/php-pdo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
