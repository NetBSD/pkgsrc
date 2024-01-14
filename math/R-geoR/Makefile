# $NetBSD: Makefile,v 1.16 2024/01/14 05:17:27 mef Exp $

R_PKGNAME=	geoR
R_PKGVER=	1.9-3

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Analysis of geostatistical data
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

#EPENDS+=	R-RandomFields>=2.0.54:../../math/R-RandomFields
DEPENDS+=	R-sp>=1.3.1:../../math/R-sp
DEPENDS+=	R-splancs>=2.01.39:../../math/R-splancs

# Package suggested but not available: 'scatterplot3d'
#TEST_DEPENDS+=	R-scatterplot3d-[0-9]*:../../

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
