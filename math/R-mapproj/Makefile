# $NetBSD: Makefile,v 1.7 2013/08/31 08:43:23 joerg Exp $

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/mapproj/
COMMENT=	Converts latitude/longitude into projected coordinates
LICENSE=	lucent

R_PKGNAME=	mapproj
R_PKGVER=	1.2-1

DEPENDS+=	R-maps>=2.2.5:../../math/R-maps

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
