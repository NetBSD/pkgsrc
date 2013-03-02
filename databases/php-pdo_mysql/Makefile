# $NetBSD: Makefile,v 1.16 2013/03/02 20:33:24 wiz Exp $

MODNAME=		pdo_mysql
PKGREVISION=		1
CATEGORIES+=		databases
COMMENT=		PHP extension for PHP Data Objects (MySQL)

USE_PHP_EXT_PATCHES=	yes

.include "../../mk/bsd.prefs.mk"

.include "../../lang/php/ext.mk"

CONFIGURE_ARGS+=	--with-${MODNAME}
CONFIGURE_ARGS+=	--with-${PKGMODNAME}=shared,${BUILDLINK_PREFIX.mysql-client}

.include "../../mk/mysql.buildlink3.mk"
.include "../../databases/php-pdo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

