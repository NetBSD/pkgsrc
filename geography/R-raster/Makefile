# $NetBSD: Makefile,v 1.1 2020/08/08 23:28:07 brook Exp $

R_PKGNAME=	raster
R_PKGVER=	3.0-12
CATEGORIES=	geography

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Geographic Data Analysis and Modeling
LICENSE=	gnu-gpl-v3

USE_LANGUAGES+=	c c++

DEPENDS+=	R-sp>=1.2.0:../../math/R-sp

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../math/R-sp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
