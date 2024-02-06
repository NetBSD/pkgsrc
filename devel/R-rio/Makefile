# $NetBSD: Makefile,v 1.7 2024/02/06 12:47:05 mef Exp $

R_PKGNAME=	rio
R_PKGVER=	1.0.1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Swiss-army knife for data I/O
LICENSE=	gnu-gpl-v2

DEPENDS+=	R-R.utils-[0-9]*:../../devel/R-R.utils
DEPENDS+=	R-curl>=0.6:../../www/R-curl
DEPENDS+=	R-data.table>=1.9.8:../../textproc/R-data.table
DEPENDS+=	R-haven>=1.1.0:../../textproc/R-haven
DEPENDS+=	R-openxlsx>=4.1.0.1:../../textproc/R-openxlsx
DEPENDS+=	R-readxl>=0.1.1:../../textproc/R-readxl
DEPENDS+=	R-tibble>=2.1.3:../../math/R-tibble
DEPENDS+=	R-writexl-[0-9]*:../../textproc/R-writexl

# Packages suggested but not available:
#   'fst', 'hexView', 'pzfx', 'readODS', 'rmatio', 'qs', 'arrow'

TEST_DEPENDS+=	R-bit64-[0-9]*:../../devel/R-bit64
#TEST_DEPENDS+=	R-arrow-[0-9]*
#EST_DEPENDS+=	R-feather-[0-9]*:../../devel/R-feather
#TEST_DEPENDS+=	R-fst-[0-9]*
#TEST_DEPENDS+=	R-hexView-[0-9]*
#TEST_DEPENDS+=	R-pzfx-[0-9]*
#TEST_DEPENDS+=	R-readODS-[0-9]*
#EST_DEPENDS+=	R-rmatio-[0-9]*
TEST_DEPENDS+=	R-jsonlite-[0-9]*:../../textproc/R-jsonlite
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat
TEST_DEPENDS+=	R-xml2-[0-9]*:../../textproc/R-xml2
TEST_DEPENDS+=	R-yaml-[0-9]*:../../textproc/R-yaml

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
