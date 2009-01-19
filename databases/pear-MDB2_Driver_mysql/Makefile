# $NetBSD: Makefile,v 1.3 2009/01/19 20:13:38 abs Exp $

DISTNAME=	MDB2_Driver_mysql-1.5.0b2
CATEGORIES=	databases

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://pear.php.net/package/MDB2_Driver_mysql
COMMENT=	Mysql MDB2 driver

DEPENDS+=	${PHP_PKG_PREFIX}-mysql-[0-9]*:../../databases/php-mysql
DEPENDS+=	${PHP_PKG_PREFIX}-pear-MDB2>=2.5:../../databases/pear-MDB2

PEAR_DIRRM_EXCLUDE=	lib/php/MDB2

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
