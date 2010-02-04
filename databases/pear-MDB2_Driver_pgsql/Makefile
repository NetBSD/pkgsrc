# $NetBSD: Makefile,v 1.5 2010/02/04 16:36:05 joerg Exp $

DISTNAME=	MDB2_Driver_pgsql-1.5.0b2
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pear.php.net/package/MDB2_Driver_pgsql
COMMENT=	Pgsql MDB2 driver

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${PHP_PKG_PREFIX}-pgsql-[0-9]*:../../databases/php-pgsql
DEPENDS+=	${PHP_PKG_PREFIX}-pear-MDB2>=2.5:../../databases/pear-MDB2

PEAR_DIRRM_EXCLUDE=	lib/php/MDB2

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
