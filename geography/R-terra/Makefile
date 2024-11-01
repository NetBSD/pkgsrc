# $NetBSD: Makefile,v 1.11 2024/11/01 12:52:45 wiz Exp $

R_PKGNAME=	terra
R_PKGVER=	1.7-39
PKGREVISION=	10
CATEGORIES=	geography

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Spatial Data Analysis
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c c++

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../geography/gdal-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
