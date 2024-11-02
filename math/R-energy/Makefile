# $NetBSD: Makefile,v 1.6 2024/11/02 02:23:55 mef Exp $

R_PKGNAME=	energy
R_PKGVER=	1.7-12

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	E-statistics: multivariate inference via the energy of data
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-gsl-[0-9]*:../../math/R-gsl

# Package suggested but not available: 'CompQuadForm'
TEST_DEPENDS+=	R-CompQuadForm-[0-9]*:../../math/R-CompQuadForm
TEST_DEPENDS+=	R-gsl-[0-9]*:../../math/R-gsl
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown

TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

USE_LANGUAGES=	c c++

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
