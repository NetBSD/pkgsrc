# $NetBSD: Makefile,v 1.2 2021/11/28 00:49:54 mef Exp $

R_PKGNAME=	cachem
R_PKGVER=	1.0.6
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Cache R Objects with Automatic Pruning
LICENSE=	mit	# + file LICENSE

DEPENDS+=	R-rlang>=0.4.10:../../devel/R-rlang
DEPENDS+=	R-fastmap-[0-9]*:../../devel/R-fastmap

TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
