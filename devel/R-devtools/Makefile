# $NetBSD: Makefile,v 1.1 2019/08/09 19:13:05 brook Exp $

R_PKGNAME=	devtools
R_PKGVER=	2.1.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Tools to make developing R packages easier
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-callr>=3.3.1:../../devel/R-callr
DEPENDS+=	R-cli>=1.1.0:../../devel/R-cli
DEPENDS+=	R-git2r>=0.23.0:../../devel/R-git2r
DEPENDS+=	R-memoise>=1.0.0:../../devel/R-memoise
DEPENDS+=	R-pkgbuild>=1.0.3:../../devel/R-pkgbuild
DEPENDS+=	R-pkgload>=1.0.2:../../devel/R-pkgload
DEPENDS+=	R-rcmdcheck>=1.3.3:../../devel/R-rcmdcheck
DEPENDS+=	R-remotes>=2.1.0:../../devel/R-remotes
DEPENDS+=	R-roxygen2>=6.1.1:../../devel/R-roxygen2
DEPENDS+=	R-sessioninfo>=1.1.1:../../devel/R-sessioninfo
DEPENDS+=	R-testthat>=2.1.1:../../devel/R-testthat
DEPENDS+=	R-usethis>=1.5.0:../../devel/R-usethis
DEPENDS+=	R-withr>=2.1.2:../../devel/R-withr
DEPENDS+=	R-rstudioapi>=0.7:../../math/R-rstudioapi
DEPENDS+=	R-digest>=0.6.20:../../security/R-digest
DEPENDS+=	R-jsonlite>=1.6:../../textproc/R-jsonlite
DEPENDS+=	R-httr>=0.4:../../www/R-httr

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
