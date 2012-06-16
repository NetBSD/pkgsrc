# $NetBSD: Makefile,v 1.8 2012/06/16 02:52:03 taca Exp $

DISTNAME=	MDB2_Driver_sqlite-1.5.0b3
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pear.php.net/package/MDB2_Driver_sqlite
COMMENT=	Sqlite MDB2 driver

PKG_DESTDIR_SUPPORT=	user-destdir

PHP_VERSIONS_ACCEPTED=	52 53

DEPENDS+=       ${PHP_PKG_PREFIX}-sqlite-[0-9]*:../../databases/php-sqlite
DEPENDS+=	${PHP_PKG_PREFIX}-pear-MDB2>=2.5:../../databases/pear-MDB2

PEAR_DIRRM_EXCLUDE=	lib/php/MDB2

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
