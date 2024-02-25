# $NetBSD: Makefile,v 1.4 2024/02/25 01:58:27 mef Exp $

R_PKGNAME=	estimability
R_PKGVER=	1.5

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Tools for assessing estimability of linear predictions
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	# none

TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown

TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url



.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
