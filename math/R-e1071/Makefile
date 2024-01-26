# $NetBSD: Makefile,v 1.15 2024/01/26 10:55:59 mef Exp $

R_PKGNAME=	e1071
R_PKGVER=	1.7-14

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Misc Functions of the Department of Statistics (e1071), TU Wien
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-proxy-[0-9]*:../../math/R-proxy

TEST_DEPENDS+=	R-mlbench-[0-9]*:../../benchmarks/R-mlbench
TEST_DEPENDS+=	R-randomForest-[0-9]*:../../math/R-randomForest
TEST_DEPENDS+=	R-slam-[0-9]*:../../math/R-slam
TEST_DEPENDS+=	R-SparseM-[0-9]*:../../math/R-SparseM
TEST_DEPENDS+=	R-xtable-[0-9]*:../../math/R-xtable

# !pdfTeX error: pdflatex (file ectt0900): Font ectt0900 at 600 not found
TEST_DEPENDS+=	tex-a4wide-[0-9]*:../../print/tex-a4wide
TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-hyperref-[0-9]*:../../print/tex-hyperref
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-natbib-[0-9]*:../../print/tex-natbib
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

USE_LANGUAGES=	c c++

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
