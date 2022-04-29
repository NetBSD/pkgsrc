# $NetBSD: Makefile,v 1.5 2022/04/29 13:13:51 mef Exp $

R_PKGNAME=	pkgbuild
R_PKGVER=	1.3.1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Find tools needed to build R packages
LICENSE=	mit

DEPENDS+=	R-callr>=3.2.0:../../devel/R-callr
DEPENDS+=	R-cli>=1.1.0:../../devel/R-cli
DEPENDS+=	R-crayon>=1.3.4:../../devel/R-crayon
DEPENDS+=	R-desc>=1.2.0:../../devel/R-desc
DEPENDS+=	R-rprojroot>=1.3.2:../../devel/R-rprojroot
DEPENDS+=	R-withr>=2.1.2:../../devel/R-withr
DEPENDS+=	R-prettyunits>=1.0.2:../../math/R-prettyunits

TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat
TEST_DEPENDS+=	R-cpp11-[0-9]*:../../lang/R-cpp11
TEST_DEPENDS+=	R-Rcpp-[0-9]*:../../devel/R-Rcpp
TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr

# need for make test
USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
