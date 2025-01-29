# $NetBSD: Makefile,v 1.9 2025/01/29 11:49:14 mef Exp $

R_PKGNAME=	Hmisc
R_PKGVER=	5.2-2
CATEGORIES=	misc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Harrell miscellaneous
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-base64enc>=0.1.3:../../converters/R-base64enc
DEPENDS+=	R-ggplot2>=2.2:../../graphics/R-ggplot2
DEPENDS+=	R-latticeExtra>=0.6.28:../../graphics/R-latticeExtra
DEPENDS+=	R-viridis>=0.5.1:../../graphics/R-viridis
DEPENDS+=	R-Formula>=1.2.3:../../math/R-Formula
DEPENDS+=	R-acepack>=1.4.1:../../math/R-acepack
DEPENDS+=	R-gtable>=0.3.0:../../math/R-gtable
DEPENDS+=	R-data.table>=1.12.2:../../textproc/R-data.table
DEPENDS+=	R-htmlTable>=1.11.0:../../textproc/R-htmlTable
DEPENDS+=	R-htmltools>=0.3.6:../../textproc/R-htmltools

# Packages suggested but not available:
#   'qreport', 'rms', 'mice', 'tables', 'plotly', 'leaps', 'polspline',
#   'kableExtra', 'gt', 'sparkline', 'qs', 'keyring', 'safer', 'htm2txt'

TEST_DEPENDS+=	R-abind-[0-9]*:../../math/R-abind
TEST_DEPENDS+=	R-base64enc-[0-9]*:../../converters/R-base64enc
TEST_DEPENDS+=	R-chron-[0-9]*:../../math/R-chron
TEST_DEPENDS+=	R-Formula-[0-9]*:../../math/R-Formula
TEST_DEPENDS+=	R-gridExtra-[0-9]*:../../graphics/R-gridExtra
TEST_DEPENDS+=	R-htmlTable-[0-9]*:../../textproc/R-htmlTable
TEST_DEPENDS+=	R-htmltools-[0-9]*:../../textproc/R-htmltools
TEST_DEPENDS+=	R-latticeExtra-[0-9]*:../../graphics/R-latticeExtra
TEST_DEPENDS+=	R-pcaPP-[0-9]*:../../math/R-pcaPP
TEST_DEPENDS+=	R-rio-[0-9]*:../../devel/R-rio
TEST_DEPENDS+=	R-VGAM-[0-9]*:../../math/R-VGAM
TEST_DEPENDS+=	R-viridis-[0-9]*:../../graphics/R-viridis
TEST_DEPENDS+=	R-getPass-[0-9]*:../../security/R-getPass
#EST_DEPENDS+=	R-rms-[0-9]*:
#EST_DEPENDS+=	R-mice-[0-9]*:
#EST_DEPENDS+=	R-tables-[0-9]*:
#EST_DEPENDS+=	R-plotly-[0-9]*:

USE_LANGUAGES=	c fortran

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
