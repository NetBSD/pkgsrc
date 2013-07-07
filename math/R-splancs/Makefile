# $NetBSD: Makefile,v 1.2 2013/07/07 11:20:24 wen Exp $

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/splancs/
COMMENT=	Spatial and space-time point pattern analysis
LICENSE=	gnu-gpl-v2

R_PKGNAME=	splancs
R_PKGVER=	2.01-33

USE_LANGUAGES+=	c fortran

DEPENDS+=	R-sp>=0.9.98:../../math/R-sp

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
