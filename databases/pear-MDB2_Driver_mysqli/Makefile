# $NetBSD: Makefile,v 1.1.1.1 2010/12/22 15:34:53 taca Exp $

DISTNAME=	MDB2_Driver_mysqli-1.5.0b3
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pear.php.net/package/MDB2_Driver_mysqli
COMMENT=	Mysqli MDB2 driver

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${PHP_PKG_PREFIX}-mysqli-[0-9]*:../../databases/php-mysqli
DEPENDS+=	${PHP_PKG_PREFIX}-pear-MDB2>=2.5:../../databases/pear-MDB2

PEAR_DIRRM_EXCLUDE=	lib/php/MDB2

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
