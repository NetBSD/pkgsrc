# $NetBSD: Makefile,v 1.9 2024/01/23 13:32:34 mef Exp $

R_PKGNAME=	waldo
R_PKGVER=	0.5.2
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Find Differences Between R Objects
LICENSE=	mit	# + file LICENSE

DEPENDS+=	R-cli>=2.0.2:../../devel/R-cli
DEPENDS+=	R-diffobj-[0-9]*:../../devel/R-diffobj
DEPENDS+=	R-fansi>=0.4.0:../../devel/R-fansi
DEPENDS+=	R-glue>=1.4.1:../../devel/R-glue
DEPENDS+=	R-rematch2>=2.1.2:../../devel/R-rematch2
DEPENDS+=	R-rlang>=0.4.7:../../devel/R-rlang
DEPENDS+=	R-tibble>=2.1.3:../../math/R-tibble

TEST_DEPENDS+=	R-rematch2-[0-9]*:../../devel/R-rematch2
TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr
TEST_DEPENDS+=	R-xml2-[0-9]*:../../textproc/R-xml2
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat

TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
