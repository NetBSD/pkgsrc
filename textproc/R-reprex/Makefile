# $NetBSD: Makefile,v 1.1 2022/04/23 05:35:10 mef Exp $

R_PKGNAME=	reprex
R_PKGVER=	2.0.1
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Prepare Reproducible Example Code via the Clipboard
LICENSE=	mit	# + file LICENSE

DEPENDS+=	R-callr>=3.6.0:../../devel/R-callr
DEPENDS+=	R-cli>=2.3.1:../../devel/R-cli
DEPENDS+=	R-clipr>=0.4.0:../../devel/R-clipr
DEPENDS+=	R-fs>=1.5.2:../../devel/R-fs
DEPENDS+=	R-glue>=1.6.2:../../devel/R-glue
DEPENDS+=	R-rlang>=0.4.0:../../devel/R-rlang
DEPENDS+=	R-withr>=2.3.0:../../devel/R-withr
DEPENDS+=	R-rstudioapi>=0.13:../../math/R-rstudioapi
DEPENDS+=	R-knitr>=1.23:../../print/R-knitr
DEPENDS+=	R-rmarkdown>=2.10:../../textproc/R-rmarkdown

# Packages suggested but not available: 'fortunes', 'mockr', 'styler'

TEST_DEPENDS+=	R-spelling-[0-9]*:../../textproc/R-spelling
TEST_DEPENDS+=	R-shiny-[0-9]*:../../www/R-shiny
TEST_DEPENDS+=	R-sessioninfo-[0-9]*:../../devel/R-sessioninfo
TEST_DEPENDS+=	R-miniUI-[0-9]*:../../www/R-miniUI


USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
