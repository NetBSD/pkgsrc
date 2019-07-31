# $NetBSD: Makefile,v 1.1 2019/07/31 13:37:02 brook Exp $

CATEGORIES=	misc R

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/Hmisc/
COMMENT=	Harrell miscellaneous
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

R_PKGNAME=	Hmisc
R_PKGVER=	4.2-0

DEPENDS+=	R-base64enc>=0.1.3:../../converters/R-base64enc
DEPENDS+=	R-ggplot2>=2.2:../../graphics/R-ggplot2
DEPENDS+=	R-viridis>=0.5.1:../../graphics/R-viridis
DEPENDS+=	R-Formula>=1.2.3:../../math/R-Formula
DEPENDS+=	R-acepack>=1.4.1:../../math/R-acepack
DEPENDS+=	R-gtable>=0.3.0:../../math/R-gtable
DEPENDS+=	R-data.table>=1.12.2:../../textproc/R-data.table
DEPENDS+=	R-htmlTable>=1.11.0:../../textproc/R-htmlTable
DEPENDS+=	R-htmltools>=0.3.6:../../textproc/R-htmltools

USE_LANGUAGES=	c fortran

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
