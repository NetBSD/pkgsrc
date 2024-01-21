# $NetBSD: Makefile,v 1.11 2024/01/21 07:51:09 mef Exp $

R_PKGNAME=	vctrs
R_PKGVER=	0.6.5

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Vector helpers
LICENSE=	gnu-gpl-v3

DEPENDS+=	R-backports>=1.1.4:../../math/R-backports
DEPENDS+=	R-cli-[0-9]*:../../devel/R-cli
DEPENDS+=	R-digest>=0.6.25:../../security/R-digest
DEPENDS+=	R-ellipsis>=0.2.0:../../math/R-ellipsis
DEPENDS+=	R-glue>=1.4.1:../../devel/R-glue
DEPENDS+=	R-lifecycle-[0-9]*:../../devel/R-lifecycle
DEPENDS+=	R-rlang>=1.0.11:../../devel/R-rlang
DEPENDS+=	R-zeallot>=0.1.0:../../math/R-zeallot

TEST_DEPENDS+=	R-bit64-[0-9]*:../../devel/R-bit64
TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr
TEST_DEPENDS+=	R-dplyr-[0-9]*:../../math/R-dplyr
TEST_DEPENDS+=	R-generics-[0-9]*:../../math/R-generics
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-markdown-[0-9]*:../../textproc/R-markdown
TEST_DEPENDS+=	R-pkgdown-[0-9]*:../../www/R-pkgdown
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat
TEST_DEPENDS+=	R-xml2-[0-9]*:../../textproc/R-xml2

TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

USE_LANGUAGES=	c c++

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
