# $NetBSD: Makefile,v 1.22 2021/07/02 15:21:35 nia Exp $

PKGREVISION=		2
MODNAME=		pdo_mysql
CATEGORIES+=		databases
COMMENT=		PHP extension for PHP Data Objects (MySQL)

USE_PHP_EXT_PATCHES=	yes

.include "options.mk"
.include "../../databases/php-pdo/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
