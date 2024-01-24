# $NetBSD: Makefile,v 1.9 2024/01/24 11:37:11 mef Exp $

R_PKGNAME=	RcppEigen
R_PKGVER=	0.3.3.9.4

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Rcpp integration for the Eigen templated linear algebra library
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3	# OR file LICENSE

TEST_DEPENDS+=	R-tinytest-[0-9]*:../../devel/R-tinytest
TEST_DEPENDS+=	R-inline-[0-9]*:../../devel/R-inline
TEST_DEPENDS+=	R-pkgKitten-[0-9]*:../../devel/R-pkgKitten
TEST_DEPENDS+=	R-microbenchmark-[0-9]*:../../benchmarks/R-microbenchmark
TEST_DEPENDS+=	tex-thumbpdf-[0-9]*:../../print/tex-thumbpdf

TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-natbib-[0-9]*:../../print/tex-natbib
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
TEST_DEPENDS+=	tex-hyperref-[0-9]*:../../print/tex-hyperref

USE_LANGUAGES=		c c++ fortran
USE_CXX_FEATURES+=	c++11

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
