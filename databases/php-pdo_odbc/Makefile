# $NetBSD: Makefile,v 1.14 2025/02/08 03:10:22 taca Exp $

MODNAME=		pdo_odbc
PKGREVISION=		1
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
