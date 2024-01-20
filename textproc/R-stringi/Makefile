# $NetBSD: Makefile,v 1.31 2024/01/20 12:43:54 mef Exp $

R_PKGNAME=	stringi
R_PKGVER=	1.8.3
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Character string processing facilities
LICENSE=	modified-bsd	# + file LICENSE

TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval
# !pdfTeX error: pdflatex (file tctt0900): Font tctt0900 at 600 not found
TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

.include "../../math/R/Makefile.extension"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
