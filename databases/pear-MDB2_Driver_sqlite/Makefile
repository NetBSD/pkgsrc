# $NetBSD: Makefile,v 1.3 2009/07/13 14:48:36 joerg Exp $

DISTNAME=	MDB2_Driver_sqlite-1.5.0b2
CATEGORIES=	databases

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://pear.php.net/package/MDB2_Driver_sqlite
COMMENT=	Sqlite MDB2 driver

PHP_VERSIONS_ACCEPTED=	5

DEPENDS+=       ${PHP_PKG_PREFIX}-sqlite-[0-9]*:../../databases/php-sqlite
DEPENDS+=	${PHP_PKG_PREFIX}-pear-MDB2>=2.5:../../databases/pear-MDB2

PEAR_DIRRM_EXCLUDE=	lib/php/MDB2

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
