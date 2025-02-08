# $NetBSD: Makefile,v 1.10 2025/02/08 03:30:48 taca Exp $

DISTNAME=	MDB2_Driver_pgsql-1.5.0b4
PKGREVISION=	1
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pear.php.net/package/MDB2_Driver_pgsql
COMMENT=	Pgsql MDB2 driver
LICENSE=	modified-bsd

DEPENDS+=	${PHP_PKG_PREFIX}-pgsql>=${PHP_BASE_VERS}:../../databases/php-pgsql
DEPENDS+=	${PHP_PKG_PREFIX}-pear-MDB2>=2.5:../../databases/pear-MDB2

PEAR_DIRRM_EXCLUDE=	lib/php/MDB2

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
