# $NetBSD: Makefile,v 1.7 2024/11/28 22:39:35 mef Exp $

R_PKGNAME=	maps
R_PKGVER=	3.4.2.1
CATEGORIES=	geography

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/maps/
COMMENT=	Draw Geographical Maps
LICENSE=	gnu-gpl-v2

TEST_DEPENDS+=	R-mapdata-[0-9]*:../../geography/R-mapdata
TEST_DEPENDS+=	R-mapproj-[0-9]*:../../math/R-mapproj
TEST_DEPENDS+=	R-sp-[0-9]*:../../math/R-sp
TEST_DEPENDS+=	R-rnaturalearth-[0-9]*:../../geography/R-rnaturalearth

TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

USE_TOOLS+=	gmake

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
