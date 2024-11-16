# $NetBSD: Makefile,v 1.13 2024/11/16 01:42:54 mef Exp $

R_PKGNAME=	randomForest
R_PKGVER=	4.7-1.2

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Breiman and Cutler's Random Forests for Classification and Regression
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

USE_LANGUAGES=	c fortran

TEST_DEPENDS+=	R-RColorBrewer-[0-9]*:../../math/R-RColorBrewer

# !pdfTeX error: pdflatex (file tctt0900): Font tctt0900 at 600 not found
TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
