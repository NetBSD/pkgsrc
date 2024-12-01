# $NetBSD: Makefile,v 1.2 2024/12/01 14:03:45 mef Exp $

R_PKGNAME=	spatstat.random
R_PKGVER=	3.3-2
CATEGORIES=	geography

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Random Generation Functionality for the 'spatstat' Family
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-spatstat.data>=3.0:../../geography/R-spatstat.data
DEPENDS+=	R-spatstat.geom>=3.2.1:../../geography/R-spatstat.geom
DEPENDS+=	R-spatstat.utils>=3.0.2:../../geography/R-spatstat.utils

TEST_DEPENDS+=	R-spatstat.linnet-[0-9]*:../../geography/R-spatstat.linnet
TEST_DEPENDS+=	R-spatstat.explore-[0-9]*:../../geography/R-spatstat.explore
TEST_DEPENDS+=	R-spatstat.model-[0-9]*:../../geography/R-spatstat.model
TEST_DEPENDS+=	R-spatstat-[0-9]*:../../geography/R-spatstat
TEST_DEPENDS+=	R-gsl-[0-9]*:../../math/R-gsl

# !pdfTeX error: pdflatex (file tctt0900): Font tctt0900 at 600 not found
TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

USE_LANGUAGES=	c c++

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
