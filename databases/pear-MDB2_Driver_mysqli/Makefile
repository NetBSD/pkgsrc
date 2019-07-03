# $NetBSD: Makefile,v 1.4 2019/07/03 07:28:21 nia Exp $

DISTNAME=	MDB2_Driver_mysqli-1.5.0b4
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pear.php.net/package/MDB2_Driver_mysqli
COMMENT=	Mysqli MDB2 driver
LICENSE=	modified-bsd

DEPENDS+=	${PHP_PKG_PREFIX}-mysqli-[0-9]*:../../databases/php-mysqli
DEPENDS+=	${PHP_PKG_PREFIX}-pear-MDB2>=2.5:../../databases/pear-MDB2

PEAR_DIRRM_EXCLUDE=	lib/php/MDB2

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
