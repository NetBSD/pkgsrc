# $NetBSD: Makefile,v 1.1 2020/08/08 22:52:57 brook Exp $

R_PKGNAME=	units
R_PKGVER=	0.6-5

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Measurement Units for R Vectors
LICENSE=	gnu-gpl-v2

USE_LANGUAGES+=	c c++

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../math/udunits/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
