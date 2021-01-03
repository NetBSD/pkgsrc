# $NetBSD: Makefile,v 1.7 2021/01/03 10:04:58 mef Exp $

R_PKGNAME=	RcppEigen
R_PKGVER=	0.3.3.9.1

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Rcpp integration for the Eigen templated linear algebra library
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3	# OR file LICENSE

TEST_DEPENDS+=	R-tinytest-[0-9]*:../../devel/R-tinytest
TEST_DEPENDS+=	R-inline-[0-9]*:../../devel/R-inline
TEST_DEPENDS+=	R-pkgKitten-[0-9]*:../../devel/R-pkgKitten
TEST_DEPENDS+=	R-microbenchmark-[0-9]*:../../benchmarks/R-microbenchmark
TEST_DEPENDS+=	tex-thumbpdf-[0-9]*:../../print/tex-thumbpdf
# Still getting followin error by make test
# !pdfTeX error: pdflatex (file tctt1095): Font tctt1095 at 600 not found
TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec

USE_LANGUAGES=	c c++11 fortran

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
