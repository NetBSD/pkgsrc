# $NetBSD: Makefile,v 1.12 2024/10/20 01:29:10 mef Exp $

R_PKGNAME=	repr
R_PKGVER=	1.1.7
CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Serializable representations
LICENSE=	gnu-gpl-v3

DEPENDS+=	R-base64enc>=0.1.3:../../converters/R-base64enc
DEPENDS+=	R-pillar>=1.4.0:../../misc/R-pillar
DEPENDS+=	R-htmltools>=0.3.6:../../textproc/R-htmltools
DEPENDS+=	R-jsonlite>=1.6:../../textproc/R-jsonlite

# Package suggested but not available: 'leaflet'
#
# Packages which this enhances but not available for checking:
#   'vegalite', 'plotly', 'geojsonio'


TEST_DEPENDS+=	R-Cairo-[0-9]*:../../graphics/R-Cairo
TEST_DEPENDS+=	R-data.table-[0-9]*:../../textproc/R-data.table
TEST_DEPENDS+=	R-highr-[0-9]*:../../textproc/R-highr
TEST_DEPENDS+=	R-htmlwidgets-[0-9]*:../../www/R-htmlwidgets
TEST_DEPENDS+=	R-stringr-[0-9]*:../../textproc/R-stringr
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat


USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
