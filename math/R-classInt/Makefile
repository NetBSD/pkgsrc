# $NetBSD: Makefile,v 1.17 2024/01/25 13:32:00 mef Exp $

R_PKGNAME=	classInt
R_PKGVER=	0.4-10

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Choose univariate class intervals
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-e1071>=1.7.2:../../math/R-e1071

TEST_DEPENDS+=	R-spData-[0-9]*:../../geography/R-spData
TEST_DEPENDS+=	R-units-[0-9]*:../../math/R-units
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-tinytest-[0-9]*:../../devel/R-tinytest

TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url

USE_LANGUAGES=	c fortran

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
