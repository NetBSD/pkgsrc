# $NetBSD: Makefile,v 1.1 2024/11/29 15:04:26 mef Exp $

R_PKGNAME=	PROJ
R_PKGVER=	0.5.0

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Generic Coordinate System Transformations Using 'PROJ'
LICENSE=	gnu-gpl-v3

DEPENDS+=	R-lifecycle>=1.0.4:../../devel/R-lifecycle

# Packages suggested but not available:
#  'testthat', 'spelling', 'knitr', 'rmarkdown', 'sf'
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat
TEST_DEPENDS+=	R-spelling-[0-9]*:../../textproc/R-spelling
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-sf-[0-9]*:../../geography/R-sf

TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

USE_LANGUAGES=	c c++

.include "../../geography/proj/buildlink3.mk"
.include "../../math/R/Makefile.extension"
.include "../../geography/R-wk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
