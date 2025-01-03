# $NetBSD: Makefile,v 1.4 2025/01/03 08:09:58 mef Exp $

R_PKGNAME=	openxlsx
R_PKGVER=	4.2.7.1
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Read, write and edit XLSX files
LICENSE=	mit

DEPENDS+=	R-zip>=2.0.3:../../archivers/R-zip
DEPENDS+=	R-stringi-[0-9]*:../../textproc/R-stringi

# Packages suggested but not available: 'formula.tools'

TEST_DEPENDS+=	R-curl-[0-9]*:../../www/R-curl
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat
TEST_DEPENDS+=	R-roxygen2-[0-9]*:../../devel/R-roxygen2
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown

USE_LANGUAGES=	c c++

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
