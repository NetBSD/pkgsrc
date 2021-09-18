# $NetBSD: Makefile,v 1.9 2021/09/18 12:25:31 mef Exp $

R_PKGNAME=	splancs
R_PKGVER=	2.01-42

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Spatial and space-time point pattern analysis
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-sp>=0.9:../../math/R-sp

USE_LANGUAGES+=	c fortran

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
