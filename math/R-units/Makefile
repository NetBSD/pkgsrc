# $NetBSD: Makefile,v 1.5 2023/06/01 22:38:59 mef Exp $

R_PKGNAME=	units
R_PKGVER=	0.8-2

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Measurement Units for R Vectors
LICENSE=	gnu-gpl-v2

# Packages suggested but not available:
#   'NISTunits', 'measurements', 'vdiffr'
TEST_DEPENDS+=	R-ggplot2-[0-9]*:../../graphics/R-ggplot2

USE_LANGUAGES+=	c c++

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../math/udunits/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
