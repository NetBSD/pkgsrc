# $NetBSD: Makefile,v 1.3 2019/07/31 20:25:06 brook Exp $

CATEGORIES=	math R

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://had.co.nz/reshape/
COMMENT=	Flexibly reshape data: a reboot of the reshape package
LICENSE=	mit

R_PKGNAME=	reshape2
R_PKGVER=	1.4.3

DEPENDS+=	R-plyr>=1.8.1:../../math/R-plyr
DEPENDS+=	R-stringr>=1.4.0:../../textproc/R-stringr

USE_LANGUAGES=	c++

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
