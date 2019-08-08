# $NetBSD: Makefile,v 1.8 2019/08/08 19:53:54 brook Exp $

R_PKGNAME=	splancs
R_PKGVER=	2.01-40
CATEGORIES=	math

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Spatial and space-time point pattern analysis
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-sp>=0.9:../../math/R-sp

USE_LANGUAGES+=	c fortran

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
