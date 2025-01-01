# $NetBSD: Makefile,v 1.7 2025/01/01 02:13:05 mef Exp $

R_PKGNAME=	rmarkdown
R_PKGVER=	2.29
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Dynamic Documents for R
LICENSE=	gnu-gpl-v3

DEPENDS+=	R-base64enc>=0.1.3:../../converters/R-base64enc
DEPENDS+=	R-evaluate>=0.13:../../devel/R-evaluate
DEPENDS+=	R-xfun>=0.8:../../devel/R-xfun
DEPENDS+=	R-mime>=0.7:../../mail/R-mime
DEPENDS+=	R-knitr>=1.22:../../print/R-knitr
DEPENDS+=	R-htmltools>=0.3.5:../../textproc/R-htmltools
DEPENDS+=	R-jsonlite>=1.6:../../textproc/R-jsonlite
DEPENDS+=	R-stringr>=1.2.0:../../textproc/R-stringr
DEPENDS+=	R-yaml>=2.1.19:../../textproc/R-yaml
DEPENDS+=	R-tinytex-[0-9]*:../../print/R-tinytex
DEPENDS+=	R-withr>=2.4.2:../../devel/R-withr
DEPENDS+=	R-jquerylib-[0-9]*:../../www/R-jquerylib
DEPENDS+=	R-bslib>=0.2.5.1:../../www/R-bslib
DEPENDS+=	R-fontawesome-[0-9]*:../../textproc/R-fontawesome

# Packages suggested but not available:
#   'dygraphs', 'rsconnect', 'katex', 'cleanrmd', 'xml2'

# Package required and available but unsuitable version: 'fontawesome'

TEST_DEPENDS+=	R-base64enc-[0-9]*:../../converters/R-base64enc
TEST_DEPENDS+=	R-fs-[0-9]*:../../devel/R-fs
TEST_DEPENDS+=	R-shiny-[0-9]*:../../www/R-shiny
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat
TEST_DEPENDS+=	R-downlit-[0-9]*:../../www/R-downlit

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
