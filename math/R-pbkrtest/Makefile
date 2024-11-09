# $NetBSD: Makefile,v 1.8 2024/11/09 14:09:56 mef Exp $

R_PKGNAME=	pbkrtest
R_PKGVER=	0.5.3

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Parametric bootstrap & Kenward Roger based methods for mixed model comparison
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-doBy-[0-9]*:../../math/R-doBy
DEPENDS+=	R-lme4>=1.1.10:../../math/R-lme4
DEPENDS+=	R-numDeriv-[0-9]*:../../math/R-numDeriv
DEPENDS+=	R-broom-[0-9]*:../../math/R-broom
DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr

# !pdfTeX error: pdflatex (file tcrm1000): Font tcrm1000 at 600 not found
TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
