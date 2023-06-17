# $NetBSD: Makefile,v 1.4 2023/06/17 10:39:50 mef Exp $

R_PKGNAME=	Formula
R_PKGVER=	1.2-5

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Extended model formulas
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

TEST_DEPENDS+=	tex-hyperref-[0-9]*:../../print/tex-hyperref
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-natbib-[0-9]*:../../print/tex-natbib
TEST_DEPENDS+=	tex-thumbpdf-[0-9]*:../../print/tex-thumbpdf
TEST_DEPENDS+=	tex-xcolor-[0-9]*:../../print/tex-xcolor

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
