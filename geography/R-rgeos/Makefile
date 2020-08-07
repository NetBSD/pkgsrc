# $NetBSD: Makefile,v 1.1 2020/08/07 03:15:22 brook Exp $

R_PKGNAME=	rgeos
R_PKGVER=	0.5-2
CATEGORIES=	geography

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Interface to Geometry Engine - Open Source ('GEOS')
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

USE_LANGUAGES+=	c c++

.include "../../math/R/Makefile.extension"
.include "../../geography/geos/buildlink3.mk"
.include "../../math/R-sp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
