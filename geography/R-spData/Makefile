# $NetBSD: Makefile,v 1.2 2021/06/13 12:59:08 wen Exp $

R_PKGNAME=	spData
R_PKGVER=	0.3.8
CATEGORIES=	geography

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Datasets for Spatial Analysis
LICENSE=	cc0-1.0-universal

DEPENDS+=	R-raster>=3.0.12:../../geography/R-raster

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../math/R-sp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
