# $NetBSD: Makefile,v 1.1 2025/02/15 03:48:17 mef Exp $

R_PKGNAME=	reformulas
R_PKGVER=	0.4.0

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Machinery for Processing Random Effect Formulas
LICENSE=	gnu-gpl-v3

DEPENDS+=	R-Rdpack-[0-9]*:../../textproc/R-Rdpack

TEST_DEPENDS+=	R-lme4-[0-9]*:../../math/R-lme4
TEST_DEPENDS+=	R-tinytest-[0-9]*:../../devel/R-tinytest

# !pdfTeX error: pdflatex (file tctt0900): Font tctt0900 at 600 not found
TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
