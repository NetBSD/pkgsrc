# $NetBSD: Makefile,v 1.8 2024/10/26 12:16:54 mef Exp $

R_PKGNAME=	SparseM
R_PKGVER=	1.84-2

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Sparse linear algebra
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr

# !pdfTeX error: pdflatex (file ecti1000): Font ecti1000 at 600 not found
TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url

USE_LANGUAGES=	c fortran

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
