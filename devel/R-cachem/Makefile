# $NetBSD: Makefile,v 1.3 2023/06/11 10:37:33 mef Exp $

R_PKGNAME=	cachem
R_PKGVER=	1.0.8
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Cache R Objects with Automatic Pruning
LICENSE=	mit	# + file LICENSE

DEPENDS+=	R-rlang>=0.4.10:../../devel/R-rlang
DEPENDS+=	R-fastmap>=1.1.1:../../devel/R-fastmap

TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
