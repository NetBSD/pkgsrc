# $NetBSD: Makefile,v 1.6 2023/02/18 09:26:08 mef Exp $

R_PKGNAME=	Hmisc
R_PKGVER=	4.8-0
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

TEST_DEPENDS+=	R-base64enc-[0-9]*:../../converters/R-base64enc
TEST_DEPENDS+=	R-chron-[0-9]*:../../math/R-chron
TEST_DEPENDS+=	R-Formula-[0-9]*:../../math/R-Formula
TEST_DEPENDS+=	R-gridExtra-[0-9]*:../../graphics/R-gridExtra
TEST_DEPENDS+=	R-htmlTable-[0-9]*:../../textproc/R-htmlTable
TEST_DEPENDS+=	R-htmltools-[0-9]*:../../textproc/R-htmltools
TEST_DEPENDS+=	R-latticeExtra-[0-9]*:../../graphics/R-latticeExtra
TEST_DEPENDS+=	R-VGAM-[0-9]*:../../math/R-VGAM
TEST_DEPENDS+=	R-viridis-[0-9]*:../../graphics/R-viridis
#EST_DEPENDS+=	R-rms-[0-9]*:
#EST_DEPENDS+=	R-mice-[0-9]*:
#EST_DEPENDS+=	R-tables-[0-9]*:
#EST_DEPENDS+=	R-plotly-[0-9]*:

USE_LANGUAGES=	c fortran

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
