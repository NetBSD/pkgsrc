# $NetBSD: Makefile,v 1.9 2021/06/06 13:07:29 mef Exp $

R_PKGNAME=	repr
R_PKGVER=	1.1.3
CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Serializable representations
LICENSE=	gnu-gpl-v3

DEPENDS+=	R-base64enc>=0.1.3:../../converters/R-base64enc
DEPENDS+=	R-pillar>=1.4.0:../../misc/R-pillar
DEPENDS+=	R-htmltools>=0.3.6:../../textproc/R-htmltools
DEPENDS+=	R-jsonlite>=1.6:../../textproc/R-jsonlite

# Packages suggested but not available: 'Cairo', 'leaflet'

# Packages which this enhances but not available for checking:
#  'data.table', 'vegalite', 'plotly', 'geojsonio'

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
