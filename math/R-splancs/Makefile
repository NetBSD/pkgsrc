# $NetBSD: Makefile,v 1.7 2019/07/31 20:31:28 brook Exp $

CATEGORIES=	math R

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/splancs/
COMMENT=	Spatial and space-time point pattern analysis
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

R_PKGNAME=	splancs
R_PKGVER=	2.01-40

DEPENDS+=	R-sp>=0.9.98:../../math/R-sp
DEPENDS+=	R-sp>=0.9:../../math/R-sp

USE_LANGUAGES+=	c fortran

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
