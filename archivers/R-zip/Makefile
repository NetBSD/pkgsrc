# $NetBSD: Makefile,v 1.8 2025/02/08 06:53:43 mef Exp $

R_PKGNAME=	zip
R_PKGVER=	2.3.2
CATEGORIES=	archivers

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Cross-platform 'zip' compression
LICENSE=	cc0-1.0-universal

TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr
TEST_DEPENDS+=	R-processx-[0-9]*:../../sysutils/R-processx
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat
TEST_DEPENDS+=	R-withr-[0-9]*:../../devel/R-withr

# !pdfTeX error: pdflatex (file tctt1000): Font tctt1000 at 600 not found
# mktexpk is here: but no luck
#EST_DEPENDS+=	tex-texlive-scripts-[0-9]*:../../print/tex-texlive-scripts

TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
