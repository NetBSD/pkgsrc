# $NetBSD: Makefile,v 1.4 2019/07/31 19:34:35 brook Exp $

CATEGORIES=	math R

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/geoRglm/
COMMENT=	Package for generalised linear spatial models
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

R_PKGNAME=	geoRglm
R_PKGVER=	0.9-11

DEPENDS+=	R-geoR>=1.7.5:../../math/R-geoR
DEPENDS+=	R-sp>=1.3.1:../../math/R-sp

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
