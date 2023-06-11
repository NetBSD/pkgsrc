# $NetBSD: Makefile,v 1.16 2023/06/11 04:42:04 mef Exp $

R_PKGNAME=	mapproj
R_PKGVER=	1.2.11

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Map projections
LICENSE=	lucent

DEPENDS+=	R-maps>=2.3.0:../../geography/R-maps

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
