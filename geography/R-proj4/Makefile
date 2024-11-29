# $NetBSD: Makefile,v 1.1 2024/11/29 13:49:17 mef Exp $

R_PKGNAME=	proj4
R_PKGVER=	1.0-14
CATEGORIES=	geography

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Simple interface to the PROJ.4 cartographic projections library
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++

.include "../../geography/proj/buildlink3.mk"
.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
