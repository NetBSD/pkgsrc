# $NetBSD: Makefile,v 1.10 2023/07/08 05:14:49 mef Exp $

R_PKGNAME=	intervals
R_PKGVER=	0.15.4

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Tools for working with points and intervals
LICENSE=	artistic-2.0

# !pdfTeX error: pdflatex (file tcrm1000): Font tcrm1000 at 600 not found
TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-hyperref-[0-9]*:../../print/tex-hyperref

USE_LANGUAGES=	c c++

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
