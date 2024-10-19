# $NetBSD: Makefile,v 1.8 2024/10/19 11:50:27 mef Exp $

R_PKGNAME=	bit
R_PKGVER=	4.5.0
CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Class for vectors of 1-bit booleans
LICENSE=	gnu-gpl-v2

TEST_DEPENDS+=	R-bit64-[0-9]*:../../devel/R-bit64
TEST_DEPENDS+=	R-ff-[0-9]*:../../sysutils/R-ff
TEST_DEPENDS+=	R-microbenchmark-[0-9]*:../../benchmarks/R-microbenchmark
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-roxygen2-[0-9]*:../../devel/R-roxygen2
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat

# !pdfTeX error: pdflatex (file tctt1000): Font tctt1000 at 600 not found

TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
