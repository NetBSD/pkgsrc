# $NetBSD: Makefile,v 1.9 2015/05/31 12:57:10 wen Exp $

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/mapproj/
COMMENT=	Converts latitude/longitude into projected coordinates
LICENSE=	lucent

R_PKGNAME=	mapproj
R_PKGVER=	1.2-2

DEPENDS+=	R-maps>=2.3.0:../../math/R-maps

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
