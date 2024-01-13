# $NetBSD: Makefile,v 1.1 2024/01/13 23:13:40 mef Exp $

R_PKGNAME=	spatstat.random
R_PKGVER=	3.2-2
CATEGORIES=	geography

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Random Generation Functionality for the 'spatstat' Family
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-spatstat.data>=3.0:../../geography/R-spatstat.data
DEPENDS+=	R-spatstat.geom>=3.2.1:../../geography/R-spatstat.geom
DEPENDS+=	R-spatstat.utils>=3.0.2:../../geography/R-spatstat.utils

USE_LANGUAGES=	c c++

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
