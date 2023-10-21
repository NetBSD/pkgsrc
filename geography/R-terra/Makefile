# $NetBSD: Makefile,v 1.2 2023/10/21 17:10:18 gdt Exp $

R_PKGNAME=	terra
R_PKGVER=	1.7-39
PKGREVISION=	1
CATEGORIES=	geography

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Spatial Data Analysis
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c c++

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../geography/gdal-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
