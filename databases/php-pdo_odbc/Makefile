# $NetBSD: Makefile,v 1.8 2009/10/07 05:00:58 taca Exp $

MODNAME=		pdo_odbc
CATEGORIES+=		databases
COMMENT=		PHP extension for PHP Data Objects (ODBC)

PHP_VERSIONS_ACCEPTED=	5

PKG_DESTDIR_SUPPORT=	user-destdir
USE_PHP_EXT_PATCHES=	yes

.include "../../mk/bsd.prefs.mk"

.include "../../lang/php/ext.mk"

CONFIGURE_ARGS+=	--with-${MODNAME}
CONFIGURE_ARGS+=	--with-${PKGMODNAME}=unixodbc,${BUILDLINK_PREFIX.unixodbc}

BROKEN=		module kills Apache1 or CLI PHP on startup due to threaded unixodbc

.include "../../databases/unixodbc/buildlink3.mk"
.include "../../databases/php-pdo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
