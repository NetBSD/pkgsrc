# $NetBSD: Makefile,v 1.1.1.1 2012/04/15 22:14:29 brook Exp $

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/geoRglm/
COMMENT=	Generalised linear spatial models in R
LICENSE=	gnu-gpl-v2

R_PKGNAME=	geoRglm
R_PKGVER=	0.9-2

DEPENDS+=	R-geoR>=1.7.2:../../math/R-geoR

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
