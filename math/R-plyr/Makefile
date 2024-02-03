# $NetBSD: Makefile,v 1.13 2024/02/03 12:03:16 mef Exp $

R_PKGNAME=	plyr
R_PKGVER=	1.8.9

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Tools for splitting, applying and combining data
LICENSE=	mit

# !pdfTeX error: pdflatex (file tctt0900): Font tctt0900 at 600 not found
TEST_DEPENDS+=	R-abind-[0-9]*:../../math/R-abind
TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr
TEST_DEPENDS+=	R-doParallel-[0-9]*:../../parallel/R-doParallel
TEST_DEPENDS+=	R-foreach-[0-9]*:../../devel/R-foreach
TEST_DEPENDS+=	R-iterators-[0-9]*:../../devel/R-iterators
TEST_DEPENDS+=	R-itertools-[0-9]*:../../math/R-itertools
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat

USE_LANGUAGES+=	c c++

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
