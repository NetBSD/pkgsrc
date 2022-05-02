# $NetBSD: Makefile,v 1.4 2022/05/02 12:40:15 mef Exp $

R_PKGNAME=	geosphere
R_PKGVER=	1.5-14
CATEGORIES=	geography

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/geosphere/
COMMENT=	Spherical Trigonometry
LICENSE=	gnu-gpl-v3

DEPENDS+=	R-sp>=1.2.5:../../math/R-sp

TEST_DEPENDS+=	R-raster-[0-9]*:../../geography/R-raster
TEST_DEPENDS+=	tex-hanging-[0-9]*:../../print/tex-hanging

USE_LANGUAGES+=	c c++

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
