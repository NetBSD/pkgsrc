# $NetBSD: Makefile,v 1.11 2019/07/03 07:28:21 nia Exp $

DISTNAME=	MDB2_Driver_mysql-1.5.0b4
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pear.php.net/package/MDB2_Driver_mysql
COMMENT=	Mysql MDB2 driver
LICENSE=	modified-bsd

DEPENDS+=	${PHP_PKG_PREFIX}-mysql-[0-9]*:../../databases/php-mysql
DEPENDS+=	${PHP_PKG_PREFIX}-pear-MDB2>=2.5:../../databases/pear-MDB2

PEAR_DIRRM_EXCLUDE=	lib/php/MDB2
PHP_VERSIONS_ACCEPTED=	56

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
