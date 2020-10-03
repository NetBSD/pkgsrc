# $NetBSD: Makefile,v 1.3 2020/10/03 13:38:52 mef Exp $

R_PKGNAME=	usethis
R_PKGVER=	1.6.3
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Automate package and project setup
LICENSE=	gnu-gpl-v3

DEPENDS+=	R-clipr>=0.3.0:../../devel/R-clipr
DEPENDS+=	R-crayon>=1.3.4:../../devel/R-crayon
DEPENDS+=	R-desc>=1.2.0:../../devel/R-desc
DEPENDS+=	R-fs>=1.3.0:../../devel/R-fs
DEPENDS+=	R-git2r>=0.23:../../devel/R-git2r
DEPENDS+=	R-glue>=1.3.0:../../devel/R-glue
DEPENDS+=	R-purrr>=0.3.2:../../devel/R-purrr
DEPENDS+=	R-rlang>=0.4.0:../../devel/R-rlang
DEPENDS+=	R-rprojroot>=1.2:../../devel/R-rprojroot
DEPENDS+=	R-whisker>=0.3.2:../../devel/R-whisker
DEPENDS+=	R-withr>=2.1.2:../../devel/R-withr
DEPENDS+=	R-rstudioapi>=0.10:../../math/R-rstudioapi
DEPENDS+=	R-clisymbols>=1.2.0:../../textproc/R-clisymbols
DEPENDS+=	R-yaml>=2.2.0:../../textproc/R-yaml
DEPENDS+=	R-curl>=2.7:../../www/R-curl
DEPENDS+=	R-gh>=1.0.1:../../www/R-gh
DEPENDS+=	R-rematch2-[0-9]*:../../devel/R-rematch2

TEST_DEPENDS+=	R-spelling-[0-9]*:../../textproc/R-spelling

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"


# Packages suggested but not available: 'magick', 'pkgdown', 'styler'
#
# Package required and available but unsuitable version: 'gh'
