# $NetBSD: Makefile,v 1.1.1.1 2008/04/30 21:07:17 adrianp Exp $

DISTNAME=	MDB2_Driver_sqlite-1.4.1
CATEGORIES=	databases

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://pear.php.net/package/MDB2_Driver_sqlite
COMMENT=	Sqlite MDB2 driver

DEPENDS+=       ${PHP_PKG_PREFIX}-sqlite-[0-9]*:../../databases/php-sqlite
DEPENDS+=	${PHP_PKG_PREFIX}-pear-MDB2-[0-9]*:../../databases/pear-MDB2

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
