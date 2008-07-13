# $NetBSD: Makefile,v 1.2 2008/07/13 17:55:38 tonnerre Exp $

DISTNAME=	MDB2_Driver_mysql-1.4.1
PKGREVISION=	1
CATEGORIES=	databases

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://pear.php.net/package/MDB2_Driver_mysql
COMMENT=	Mysql MDB2 driver

DEPENDS+=	${PHP_PKG_PREFIX}-mysql-[0-9]*:../../databases/php-mysql
DEPENDS+=	${PHP_PKG_PREFIX}-pear-MDB2-[0-9]*:../../databases/pear-MDB2

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
