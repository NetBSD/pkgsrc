# $NetBSD: Makefile,v 1.1 2024/06/08 20:00:16 mef Exp $

R_PKGNAME=	chemometrics
R_PKGVER=	1.4.4

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Multivariate Statistical Analysis in Chemometrics
LICENSE=	gnu-gpl-v3

DEPENDS+=	R-e1071>=1.7.14:../../math/R-e1071
DEPENDS+=	R-lars-[0-9]*:../../math/R-lars
DEPENDS+=	R-mclust>=4.0nb1:../../math/R-chemometrics
DEPENDS+=	R-pcaPP-[0-9]*:../../math/R-pcaPP
DEPENDS+=	R-pls-[0-9]*:../../math/R-pls
DEPENDS+=	R-robustbase>=0.99.0:../../math/R-robustbase
DEPENDS+=	R-som-[0-9]*:../../math/R-som

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
