# $NetBSD: Makefile,v 1.3 2024/11/29 22:42:04 mef Exp $

R_PKGNAME=	prettymapr
R_PKGVER=	0.2.5
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

TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
