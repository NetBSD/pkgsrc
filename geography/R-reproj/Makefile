# $NetBSD: Makefile,v 1.1 2024/11/29 15:20:31 mef Exp $

R_PKGNAME=	reproj
R_PKGVER=	0.7.0
CATEGORIES=	geography

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Coordinate System Transformations for Generic Map Data
LICENSE=	gnu-gpl-v3

DEPENDS+=	R-proj4-[0-9]*:../../geography/R-proj4
DEPENDS+=	R-PROJ-[0-9]*:../../geography/R-PROJ
DEPENDS+=	R-crsmeta-[0-9]*:../../geography/R-crsmeta

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
