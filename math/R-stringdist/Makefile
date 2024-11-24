# $NetBSD: Makefile,v 1.4 2024/11/24 04:24:23 mef Exp $

R_PKGNAME=	stringdist
R_PKGVER=	0.9.12

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Approximate String Matching and String Distance Functions
LICENSE=	gnu-gpl-v3

TEST_DEPENDS+=	R-tinytest-[0-9]*:../../devel/R-tinytest

# !pdfTeX error: pdflatex (file tctt1000): Font tctt1000 at 600 not found
TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-pdfpages-[0-9]*:../../print/tex-pdfpages
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
