# $NetBSD: Makefile,v 1.10 2023/06/02 14:21:34 mef Exp $

R_PKGNAME=	splancs
R_PKGVER=	2.01-43

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Spatial and space-time point pattern analysis
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-sp>=0.9:../../math/R-sp

USE_LANGUAGES+=	c fortran

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
