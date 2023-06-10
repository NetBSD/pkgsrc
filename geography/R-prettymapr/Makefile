# $NetBSD: Makefile,v 1.2 2023/06/10 12:37:41 mef Exp $

R_PKGNAME=	prettymapr
R_PKGVER=	0.2.4
CATEGORIES=	geography

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Scale Bar, North Arrow, and Pretty Margins in R
LICENSE=	gnu-gpl-v2

DEPENDS+=	R-plyr>=1.8.6:../../math/R-plyr
DEPENDS+=	R-digest>=0.6.25:../../security/R-digest
DEPENDS+=	R-rjson>=0.2.20:../../textproc/R-rjson
DEPENDS+=	R-httr>=1.4.1:../../www/R-httr

TEST_DEPENDS+=	R-maptools-[0-9]*:../../geography/R-maptools
TEST_DEPENDS+=	R-raster-[0-9]*:../../geography/R-raster
TEST_DEPENDS+=	R-rosm-[0-9]*:../../geography/R-rosm
TEST_DEPENDS+=	R-rgdal-[0-9]*:../../geography/R-rgdal
TEST_DEPENDS+=	R-sp-[0-9]*:../../math/R-sp

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
