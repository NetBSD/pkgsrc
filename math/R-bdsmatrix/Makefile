# $NetBSD: Makefile,v 1.3 2024/10/29 22:50:02 mef Exp $

R_PKGNAME=	bdsmatrix
R_PKGVER=	1.3-7

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Routines for Block Diagonal Symmetric Matrices
LICENSE=	gnu-lgpl-v2

# !pdfTeX error: pdflatex (file tctt1000): Font tctt1000 at 600 not found
TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
