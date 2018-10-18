# $NetBSD: Makefile,v 1.13 2018/10/18 16:17:25 jperkin Exp $

MODNAME=		pdo_odbc
CATEGORIES+=		databases
COMMENT=		PHP ODBC v3 Interface driver for PDO

USE_PHP_EXT_PATCHES=	yes

.include "../../mk/bsd.prefs.mk"

.include "../../lang/php/ext.mk"

CONFIGURE_ARGS+=	--with-${MODNAME}
CONFIGURE_ARGS+=	--with-${PKGMODNAME}=unixODBC,${BUILDLINK_PREFIX.unixodbc}

.include "../../databases/php-pdo/buildlink3.mk"
.include "../../databases/unixodbc/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
