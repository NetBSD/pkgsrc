# $NetBSD: Makefile,v 1.7 2024/01/20 07:27:54 mef Exp $

R_PKGNAME=	fansi
R_PKGVER=	1.0.6
CATEGORIES=	devel

MAINTAINER=	wen@NetBSD.org
COMMENT=	ANSI control sequence aware string functions
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

# !pdfTeX error: pdflatex (file tctt0900): Font tctt0900 at 600 not found

TEST_DEPENDS+=	R-unitizer-[0-9]*:../../devel/R-unitizer
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
