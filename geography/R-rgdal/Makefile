# $NetBSD: Makefile,v 1.4 2021/03/01 19:23:07 gdt Exp $

R_PKGNAME=	rgdal
R_PKGVER=	1.4-8
PKGREVISION=	2
CATEGORIES=	geography

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Bindings for the 'Geospatial' Data Abstraction Library
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3	# + file LICENSE.note

USE_TOOLS+=	pkg-config

USE_LANGUAGES+=	c c++

.include "../../math/R/Makefile.extension"
.include "../../geography/gdal-lib/buildlink3.mk"
.include "../../geography/proj/buildlink3.mk"
.include "../../math/R-sp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
