# $NetBSD: Makefile,v 1.12 2024/11/07 13:34:45 gdt Exp $

R_PKGNAME=	terra
R_PKGVER=	1.7-39
PKGREVISION=	11
CATEGORIES=	geography

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Spatial Data Analysis
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c c++

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../geography/gdal-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
