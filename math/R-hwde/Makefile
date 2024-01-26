# $NetBSD: Makefile,v 1.12 2024/01/26 21:23:05 mef Exp $

R_PKGNAME=	hwde
R_PKGVER=	0.67-3

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Models and tests for departure from Hardy-Weinberg equilibrium
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

# !pdfTeX error: pdflatex (file ecti1000): Font ecti1000 at 600 not found
TEST_DEPENDS+=	tex-a4wide-[0-9]*:../../print/tex-a4wide
TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
