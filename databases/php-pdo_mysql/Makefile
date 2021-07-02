# $NetBSD: Makefile,v 1.21 2021/07/02 15:21:12 nia Exp $

PKGREVISION=		1
MODNAME=		pdo_mysql
CATEGORIES+=		databases
COMMENT=		PHP extension for PHP Data Objects (MySQL)

USE_PHP_EXT_PATCHES=	yes

.include "options.mk"
.include "../../databases/php-pdo/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
