# $NetBSD: Makefile,v 1.6 2024/12/07 04:19:48 mef Exp $

R_PKGNAME=	munsell
R_PKGVER=	0.5.1
CATEGORIES=	graphics

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Utilities for using Munsell colours
LICENSE=	mit

DEPENDS+=	R-colorspace>=1.4.1:../../graphics/R-colorspace

# !pdfTeX error: pdflatex (file tcrm1000): Font tcrm1000 at 600 not found
TEST_DEPENDS+=	R-ggplot2-[0-9]*:../../graphics/R-ggplot2
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat

TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
