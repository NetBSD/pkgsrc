# $NetBSD: Makefile,v 1.10 2016/09/11 17:03:25 taca Exp $

DISTNAME=	MDB2_Driver_mysql-1.5.0b4
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pear.php.net/package/MDB2_Driver_mysql
COMMENT=	Mysql MDB2 driver
LICENSE=	modified-bsd

DEPENDS+=	${PHP_PKG_PREFIX}-mysql-[0-9]*:../../databases/php-mysql
DEPENDS+=	${PHP_PKG_PREFIX}-pear-MDB2>=2.5:../../databases/pear-MDB2

PEAR_DIRRM_EXCLUDE=	lib/php/MDB2
PHP_VERSIONS_ACCEPTED=	56

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
