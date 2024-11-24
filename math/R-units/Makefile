# $NetBSD: Makefile,v 1.6 2024/11/24 07:32:11 mef Exp $

R_PKGNAME=	units
R_PKGVER=	0.8-5

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Measurement Units for R Vectors
LICENSE=	gnu-gpl-v2

# Packages suggested but not available: 'NISTunits', 'measurements', 'vdiffr'

TEST_DEPENDS+=	R-dplyr-[0-9]*:../../math/R-dplyr
TEST_DEPENDS+=	R-ggplot2-[0-9]*:../../graphics/R-ggplot2
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat
TEST_DEPENDS+=	R-xml2-[0-9]*:../../textproc/R-xml2

USE_LANGUAGES+=	c c++

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../math/udunits/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
