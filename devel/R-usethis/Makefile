# $NetBSD: Makefile,v 1.5 2021/05/31 21:50:20 mef Exp $

R_PKGNAME=	usethis
R_PKGVER=	2.0.1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Automate package and project setup
LICENSE=	mit

DEPENDS+=	R-clipr>=0.3.0:../../devel/R-clipr
DEPENDS+=	R-cli-[0-9]*:../../devel/R-cli
DEPENDS+=	R-crayon>=1.3.4:../../devel/R-crayon
DEPENDS+=	R-desc>=1.2.0:../../devel/R-desc
DEPENDS+=	R-fs>=1.3.0:../../devel/R-fs
DEPENDS+=	R-gert-[0-9]*:../../devel/R-gert
DEPENDS+=	R-glue>=1.3.0:../../devel/R-glue
DEPENDS+=	R-lifecycle-[0-9]*:../../devel/R-lifecycle
DEPENDS+=	R-purrr>=0.3.2:../../devel/R-purrr
DEPENDS+=	R-rlang>=0.4.0:../../devel/R-rlang
DEPENDS+=	R-rprojroot>=1.2:../../devel/R-rprojroot
DEPENDS+=	R-withr>=2.1.2:../../devel/R-withr
DEPENDS+=	R-rstudioapi>=0.10:../../math/R-rstudioapi
DEPENDS+=	R-clisymbols>=1.2.0:../../textproc/R-clisymbols
DEPENDS+=	R-yaml>=2.2.0:../../textproc/R-yaml
DEPENDS+=	R-curl>=2.7:../../www/R-curl
DEPENDS+=	R-gh>=1.0.1:../../www/R-gh
DEPENDS+=	R-rappdirs-[0-9]*:../../devel/R-rappdirs
DEPENDS+=	R-whisker-[0-9]*:../../devel/R-whisker

TEST_DEPENDS+=	R-spelling-[0-9]*:../../textproc/R-spelling

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"


# Packages suggested but not available: 'magick', 'pkgdown', 'styler'
#
# Package required and available but unsuitable version: 'gh'
