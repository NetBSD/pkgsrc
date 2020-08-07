# $NetBSD: Makefile,v 1.1 2020/08/07 01:45:47 brook Exp $

CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/mapdata/
COMMENT=	Extra Map Databases
LICENSE=	gnu-gpl-v2

R_PKGNAME=	mapdata
R_PKGVER=	2.3.0

DEPENDS+=	R-maps>=2.0-7:../../geography/R-maps

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
