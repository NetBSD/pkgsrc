# $NetBSD: Makefile,v 1.4 2024/01/20 02:28:54 mef Exp $

R_PKGNAME=	progress
R_PKGVER=	1.2.3
CATEGORIES=	sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Terminal progress bars
LICENSE=	mit

DEPENDS+=	R-R6>=2.4.0:../../devel/R-R6
DEPENDS+=	R-crayon>=1.3.4:../../devel/R-crayon
DEPENDS+=	R-prettyunits>=1.0.2:../../math/R-prettyunits
DEPENDS+=	R-hms>=0.5.0:../../time/R-hms

TEST_DEPENDS+=	R-Rcpp-[0-9]*:../../devel/R-Rcpp
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat
TEST_DEPENDS+=	R-withr-[0-9]*:../../devel/R-withr

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
