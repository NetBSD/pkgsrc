# $NetBSD: Makefile,v 1.2 2023/06/09 00:07:37 mef Exp $

R_PKGNAME=	repurrrsive
R_PKGVER=	1.1.0

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Examples of Recursive Lists and Nested or Split Data Frames
LICENSE=	cc0-1.0-universal

DEPENDS+=	R-tibble>=3.1.4:../../math/R-tibble

#TEST_DEPENDS+=	R-gapminder-[0-9]*:
#TEST_DEPENDS+=	R-wesanderson-[0-9]*:
TEST_DEPENDS+=	R-jsonlite-[0-9]*:../../textproc/R-jsonlite
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat
TEST_DEPENDS+=	R-xml2-[0-9]*:../../textproc/R-xml2

# !pdfTeX error: pdflatex (file tctt0900): Font tctt0900 at 600 not found
#  (tctt looks included in tex-ec though)
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
