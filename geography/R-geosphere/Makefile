# $NetBSD: Makefile,v 1.3 2021/09/20 11:45:04 mef Exp $

R_PKGNAME=	geosphere
R_PKGVER=	1.5-10
CATEGORIES=	geography

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/geosphere/
COMMENT=	Spherical Trigonometry
LICENSE=	gnu-gpl-v3

DEPENDS+=	R-sp>=1.2.5:../../math/R-sp

TEST_DEPENDS+=	R-raster-[0-9]*:../../geography/R-raster

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
