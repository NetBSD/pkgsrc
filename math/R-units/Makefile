# $NetBSD: Makefile,v 1.2 2021/06/06 11:52:55 mef Exp $

R_PKGNAME=	units
R_PKGVER=	0.7-1

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
