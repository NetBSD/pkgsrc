# $NetBSD: Makefile,v 1.5 2016/11/06 03:03:16 wen Exp $

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/splancs/
COMMENT=	Spatial and space-time point pattern analysis
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

R_PKGNAME=	splancs
R_PKGVER=	2.01-39

USE_LANGUAGES+=	c fortran

DEPENDS+=	R-sp>=0.9.98:../../math/R-sp

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
