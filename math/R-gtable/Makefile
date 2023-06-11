# $NetBSD: Makefile,v 1.5 2023/06/11 06:27:29 mef Exp $

R_PKGNAME=	gtable
R_PKGVER=	0.3.3

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Arrange 'Grobs' in tables
LICENSE=	gnu-gpl-v2

DEPENDS+=	R-cli-[0-9]*:../../devel/R-cli
DEPENDS+=	R-glue-[0-9]*:../../devel/R-glue
DEPENDS+=	R-lifecycle-[0-9]*:../../devel/R-lifecycle
DEPENDS+=	R-rlang>=1.0.0:../../devel/R-rlang

TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-profvis-[0-9]*:../../benchmarks/R-profvis

TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
