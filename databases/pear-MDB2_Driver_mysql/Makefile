# $NetBSD: Makefile,v 1.6 2010/12/22 15:29:34 taca Exp $

DISTNAME=	MDB2_Driver_mysql-1.5.0b3
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pear.php.net/package/MDB2_Driver_mysql
COMMENT=	Mysql MDB2 driver

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${PHP_PKG_PREFIX}-mysql-[0-9]*:../../databases/php-mysql
DEPENDS+=	${PHP_PKG_PREFIX}-pear-MDB2>=2.5:../../databases/pear-MDB2

PEAR_DIRRM_EXCLUDE=	lib/php/MDB2

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
