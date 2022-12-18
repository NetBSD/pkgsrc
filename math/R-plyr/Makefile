# $NetBSD: Makefile,v 1.12 2022/12/18 13:43:36 mef Exp $

R_PKGNAME=	plyr
R_PKGVER=	1.8.8

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Tools for splitting, applying and combining data
LICENSE=	mit

# Packages suggested but not available: 'abind', 'itertools'
TEST_DEPENDS+=	R-doParallel-[0-9]*:../../parallel/R-doParallel
TEST_DEPENDS+=	R-foreach-[0-9]*:../../devel/R-foreach
TEST_DEPENDS+=	R-iterators-[0-9]*:../../devel/R-iterators

USE_LANGUAGES+=	c c++

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
