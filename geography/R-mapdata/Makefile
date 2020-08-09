# $NetBSD: Makefile,v 1.3 2020/08/09 17:00:09 brook Exp $

R_PKGNAME=	mapdata
R_PKGVER=	2.3.0
CATEGORIES=	geography

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/mapdata/
COMMENT=	Extra Map Databases
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake

DEPENDS+=	R-maps>=2.0-7:../../geography/R-maps

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
