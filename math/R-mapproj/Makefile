# $NetBSD: Makefile,v 1.13 2021/06/06 07:22:40 mef Exp $

R_PKGNAME=	mapproj
R_PKGVER=	1.2.7
CATEGORIES=	math

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Map projections
LICENSE=	lucent

DEPENDS+=	R-maps>=2.3.0:../../math/R-maps

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
