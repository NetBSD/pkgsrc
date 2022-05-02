# $NetBSD: Makefile,v 1.5 2022/05/02 10:57:53 mef Exp $

R_PKGNAME=	maps
R_PKGVER=	3.4.0
CATEGORIES=	geography

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/maps/
COMMENT=	Draw Geographical Maps
LICENSE=	gnu-gpl-v2

TEST_DEPENDS+=	R-mapdata-[0-9]*:../../geography/R-mapdata
TEST_DEPENDS+=	R-mapproj-[0-9]*:../../math/R-mapproj
TEST_DEPENDS+=	R-sp-[0-9]*:../../math/R-sp
TEST_DEPENDS+=	R-rnaturalearth-[0-9]*:../../geography/R-rnaturalearth

USE_TOOLS+=	gmake

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
