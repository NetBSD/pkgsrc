# $NetBSD: Makefile,v 1.1.1.1 2008/04/30 21:06:04 adrianp Exp $

DISTNAME=	MDB2_Driver_pgsql-1.4.1
CATEGORIES=	databases

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://pear.php.net/package/MDB2_Driver_pgsql
COMMENT=	Pgsql MDB2 driver

DEPENDS+=	${PHP_PKG_PREFIX}-pgsql-[0-9]*:../../databases/php-pgsql
DEPENDS+=	${PHP_PKG_PREFIX}-pear-MDB2-[0-9]*:../../databases/pear-MDB2

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
