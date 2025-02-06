# $NetBSD: Makefile,v 1.11 2025/02/06 08:48:59 adam Exp $

R_PKGNAME=	nloptr
R_PKGVER=	2.1.1

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	R interface to NLopt
PKGREVISION=	1
LICENSE=	gnu-lgpl-v3

TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-inline-[0-9]*:../../devel/R-inline
TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr
#EST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat
TEST_DEPENDS+=	R-tinytest-[0-9]*:../../devel/R-tinytest

# !pdfTeX error: pdflatex (file tctt1000): Font tctt1000 at 600 not found
TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

USE_LANGUAGES=	c c++ fortran77
USE_TOOLS+=	pkg-config

.include "../../math/R/Makefile.extension"
.include "../../math/nlopt/buildlink3.mk"
.include "../../devel/R-testthat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
