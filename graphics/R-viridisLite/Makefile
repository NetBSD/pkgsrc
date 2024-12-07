# $NetBSD: Makefile,v 1.6 2024/12/07 07:15:27 mef Exp $

R_PKGNAME=	viridisLite
R_PKGVER=	0.4.2
CATEGORIES=	graphics

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Default color maps from 'matplotlib' (lite version)
LICENSE=	mit

TEST_DEPENDS+=	R-hexbin-[0-9]*:../../math/R-hexbin
TEST_DEPENDS+=	R-ggplot2-[0-9]*:../../graphics/R-ggplot2
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat
TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr

TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
