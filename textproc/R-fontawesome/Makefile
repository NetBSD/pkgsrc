# $NetBSD: Makefile,v 1.2 2025/01/02 11:38:59 mef Exp $

R_PKGNAME=	fontawesome
R_PKGVER=	0.5.3
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Easily Work with 'Font Awesome' Icons
LICENSE=	mit	# + file LICENSE

DEPENDS+=	R-rlang>=0.4.10:../../devel/R-rlang
DEPENDS+=	R-htmltools>=0.5.1.1:../../textproc/R-htmltools

# Packages suggested but not available: 'gt', 'rsvg'

TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr
TEST_DEPENDS+=	R-dplyr-[0-9]*:../../math/R-dplyr
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
#EST_DEPENDS+=	R-rsvg-[0-9]*:
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat

TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
