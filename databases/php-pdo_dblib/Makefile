# $NetBSD: Makefile,v 1.9 2009/03/13 10:57:20 sborrill Exp $

MODNAME=		pdo_dblib
CATEGORIES+=		databases
COMMENT=		PHP extension for PHP Data Objects (FreeTDS/Sybase/MS SQL)

PHP_VERSIONS_ACCEPTED=	5

PKG_DESTDIR_SUPPORT=	user-destdir
USE_PHP_EXT_PATCHES=	yes

.include "../../mk/bsd.prefs.mk"

.include "../../lang/php/ext.mk"
# Remove the following line when PHP >= 5.2.10 is released
.include "../../databases/php-pdo/module.mk"

CONFIGURE_ARGS+=	--with-${MODNAME}
CONFIGURE_ARGS+=	--with-${PKGMODNAME}=shared,${BUILDLINK_DIR}

# requires 0.63 version to compile, doesn't compile with 0.61
BUILDLINK_API_DEPENDS.freetds+=	freetds>=0.63

.include "../../databases/freetds/buildlink3.mk"
.include "../../databases/php-pdo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
