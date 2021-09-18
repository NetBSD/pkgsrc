# $NetBSD: Makefile,v 1.3 2021/09/18 14:09:49 mef Exp $

R_PKGNAME=	units
R_PKGVER=	0.7-2

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Measurement Units for R Vectors
LICENSE=	gnu-gpl-v2

# Packages suggested but not available:
#  'udunits2', 'NISTunits', 'measurements', 'ggforce'

USE_LANGUAGES+=	c c++

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../math/udunits/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
