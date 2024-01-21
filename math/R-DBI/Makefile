# $NetBSD: Makefile,v 1.12 2024/01/21 01:38:18 mef Exp $

R_PKGNAME=	DBI
R_PKGVER=	1.2.1

MAINTAINER=	minskim@NetBSD.org
COMMENT=	R database interface
LICENSE=	gnu-lgpl-v2 OR gnu-lgpl-v2.1 OR gnu-lgpl-v3

# Packages suggested but not available:
#   'arrow', 'DBItest', 'nanoarrow', 'RMariaDB'

TEST_DEPENDS+=	R-blob-[0-9]*:../../devel/R-blob
TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr
TEST_DEPENDS+=	R-dbplyr-[0-9]*:../../databases/R-dbplyr
TEST_DEPENDS+=	R-downlit-[0-9]*:../../www/R-downlit
TEST_DEPENDS+=	R-hms-[0-9]*:../../time/R-hms
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-RSQLite-[0-9]*:../../databases/R-RSQLite
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat
TEST_DEPENDS+=	R-xml2-[0-9]*:../../textproc/R-xml2

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
