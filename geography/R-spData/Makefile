# $NetBSD: Makefile,v 1.1 2020/08/08 23:35:17 brook Exp $

R_PKGNAME=	spData
R_PKGVER=	0.3.3
CATEGORIES=	geography

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Datasets for Spatial Analysis
LICENSE=	cc0-1.0-universal

DEPENDS+=	R-raster>=3.0.12:../../geography/R-raster

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../math/R-sp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
