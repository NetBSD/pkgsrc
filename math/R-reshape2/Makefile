# $NetBSD: Makefile,v 1.2 2018/07/28 14:40:50 brook Exp $

CATEGORIES=	math

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://had.co.nz/reshape/
COMMENT=	Flexibly reshape data

R_PKGNAME=	reshape2
R_PKGVER=	1.4.3

DEPENDS+=	R-plyr>=1.8.1:../../math/R-plyr
DEPENDS+=	R-stringr-[0-9]*:../../textproc/R-stringr

USE_LANGUAGES=	c++

.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
