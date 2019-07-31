# $NetBSD: Makefile,v 1.11 2019/07/31 19:54:06 brook Exp $

CATEGORIES=	math R

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/mapproj/
COMMENT=	Map projections
LICENSE=	lucent

R_PKGNAME=	mapproj
R_PKGVER=	1.2.6

DEPENDS+=	R-maps>=2.3.0:../../math/R-maps

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
