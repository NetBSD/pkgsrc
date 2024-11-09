# $NetBSD: Makefile,v 1.1 2024/11/09 13:33:04 mef Exp $

R_PKGNAME=	Deriv
R_PKGVER=	4.1.6

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Symbolic Differentiation
LICENSE=	gnu-gpl-v3

TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat

# !pdfTeX error: pdflatex (file tctt1000): Font tctt1000 at 600 not found

TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
