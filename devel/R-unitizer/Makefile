# $NetBSD: Makefile,v 1.1 2024/01/20 07:11:24 mef Exp $

R_PKGNAME=	unitizer
R_PKGVER=	1.4.20
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Interactive R Unit Tests
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-crayon-[0-9]*:../../devel/R-crayon
DEPENDS+=	R-diffobj-[0-9]*:../../devel/R-diffobj

TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
