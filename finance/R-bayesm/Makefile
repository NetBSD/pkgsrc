# $NetBSD: Makefile,v 1.5 2026/06/02 22:11:07 mef Exp $

R_PKGNAME=	bayesm
R_PKGVER=	3.1-6
CATEGORIES=	finance

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Bayesian inference for marketing/micro-econometrics
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown

TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

USE_LANGUAGES=	c c++ fortran
# only for bmake/gmake compatibility on patch-src_Makevars
USE_TOOLS+=	gmake
GCC_REQD+=	8

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../math/R-RcppArmadillo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
