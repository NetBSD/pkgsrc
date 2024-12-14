# $NetBSD: Makefile,v 1.9 2024/12/14 01:29:33 mef Exp $

R_PKGNAME=	RSQLite
R_PKGVER=	2.3.9
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	'SQLite' interface for R
LICENSE=	gnu-lgpl-v2 OR gnu-lgpl-v2.1 OR gnu-lgpl-v3

DEPENDS+=	R-bit64>=0.9.7:../../devel/R-bit64
DEPENDS+=	R-blob>=1.2.0:../../devel/R-blob
DEPENDS+=	R-memoise>=1.1.0:../../devel/R-memoise
DEPENDS+=	R-pkgconfig>=2.0.2:../../devel/R-pkgconfig
DEPENDS+=	R-DBI>=1.1.0:../../math/R-DBI

# Packages suggested but not available: 'DBItest', 'decor'

TEST_DEPENDS+=	R-bit64-[0-9]*:../../devel/R-bit64
TEST_DEPENDS+=	R-blob-[0-9]*:../../devel/R-blob
TEST_DEPENDS+=	R-DBI-[0-9]*:../../math/R-DBI
#EST_DEPENDS+=	R-DBItest-[0-9]*:
TEST_DEPENDS+=	R-gert-[0-9]*:../../devel/R-gert
TEST_DEPENDS+=	R-gh-[0-9]*:../../www/R-gh
TEST_DEPENDS+=	R-hms-[0-9]*:../../time/R-hms
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-memoise-[0-9]*:../../devel/R-memoise
TEST_DEPENDS+=	R-pkgconfig-[0-9]*:../../devel/R-pkgconfig
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-rvest-[0-9]*:../../www/R-rvest
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat
TEST_DEPENDS+=	R-xml2-[0-9]*:../../textproc/R-xml2

USE_LANGUAGES+=	c c++

.include "../../math/R/Makefile.extension"
.include "../../devel/R-BH/buildlink3.mk"
.include "../../lang/R-cpp11/buildlink3.mk"
.include "../../devel/R-plogr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
