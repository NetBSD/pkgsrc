# $NetBSD: Makefile,v 1.4 2023/06/04 03:21:05 mef Exp $

R_PKGNAME=	mapdata
R_PKGVER=	2.3.1
CATEGORIES=	geography

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/mapdata/
COMMENT=	Extra Map Databases
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake

DEPENDS+=	R-maps>=2.0.7:../../geography/R-maps

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
