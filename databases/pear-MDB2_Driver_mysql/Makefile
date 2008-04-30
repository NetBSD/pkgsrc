# $NetBSD: Makefile,v 1.1.1.1 2008/04/30 21:05:16 adrianp Exp $

DISTNAME=	MDB2_Driver_mysql-1.4.1
CATEGORIES=	databases

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://pear.php.net/package/MDB2_Driver_mysql
COMMENT=	Mysql MDB2 driver

DEPENDS+=	${PHP_PKG_PREFIX}-mysql-[0-9]*:../../databases/php-mysql
DEPENDS+=	${PHP_PKG_PREFIX}-pear-MDB2-[0-9]*:../../databases/pear-MDB2

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
