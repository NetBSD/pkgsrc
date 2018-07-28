# $NetBSD: Makefile,v 1.10 2018/07/28 14:40:49 brook Exp $

CATEGORIES=	math

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/mapproj/
COMMENT=	Converts latitude/longitude into projected coordinates
LICENSE=	lucent

R_PKGNAME=	mapproj
R_PKGVER=	1.2-2

DEPENDS+=	R-maps>=2.3.0:../../math/R-maps

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
