# $NetBSD: Makefile,v 1.2 2025/02/03 21:48:19 mef Exp $

R_PKGNAME=	patrick
R_PKGVER=	0.3.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Parameterized Unit Testing
LICENSE=	apache-2.0

DEPENDS+=	R-purrr>=0.3.4:../../devel/R-purrr
DEPENDS+=	R-rlang>=1.0.6:../../devel/R-rlang
DEPENDS+=	R-testthat>=3.1.5:../../devel/R-testthat
DEPENDS+=	R-dplyr>=1.0.9:../../math/R-dplyr
DEPENDS+=	R-tibble>=3.1.4:../../math/R-tibble

TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
