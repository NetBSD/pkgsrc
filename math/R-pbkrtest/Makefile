# $NetBSD: Makefile,v 1.7 2023/06/13 14:06:43 mef Exp $

R_PKGNAME=	pbkrtest
R_PKGVER=	0.5.2

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Parametric bootstrap & Kenward Roger based methods for mixed model comparison
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-lme4>=1.1.10:../../math/R-lme4
DEPENDS+=	R-numDeriv-[0-9]*:../../math/R-numDeriv
DEPENDS+=	R-broom-[0-9]*:../../math/R-broom
DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr

# for a4.sty
TEST_DEPENDS+=	tex-ntgclass-[0-9]*:../../print/tex-ntgclass
# tex-boxedminipage
TEST_DEPENDS+=	tex-boxedminipage-[0-9]*:../../print/tex-boxedminipage

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
