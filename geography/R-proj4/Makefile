# $NetBSD: Makefile,v 1.2 2025/04/17 21:50:55 wiz Exp $

R_PKGNAME=	proj4
R_PKGVER=	1.0-14
PKGREVISION=	1
CATEGORIES=	geography

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Simple interface to the PROJ.4 cartographic projections library
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++

.include "../../geography/proj/buildlink3.mk"
.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
