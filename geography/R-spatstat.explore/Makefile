# $NetBSD: Makefile,v 1.2 2024/12/01 08:56:26 mef Exp $

R_PKGNAME=	spatstat.explore
R_PKGVER=	3.3-3
CATEGORIES=	geography

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Exploratory Data Analysis for the 'spatstat' Family
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-spatstat.data>=3.0.1:../../geography/R-spatstat.data
DEPENDS+=	R-spatstat.geom>=3.2.7:../../geography/R-spatstat.geom
DEPENDS+=	R-spatstat.random>=3.2.1:../../geography/R-spatstat.random
DEPENDS+=	R-spatstat.sparse>=3.1.0:../../geography/R-spatstat.sparse
#EPENDS+=	R-spatstat.utils>=3.0.3:../../geography/R-spatstat.utils
DEPENDS+=	R-abind>=1.4.5:../../math/R-abind
DEPENDS+=	R-goftest>=1.2.2:../../math/R-goftest

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
