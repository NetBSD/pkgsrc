# $NetBSD: Makefile,v 1.10 2019/08/08 19:53:48 brook Exp $

R_PKGNAME=	clim.pact
R_PKGVER=	2.3-10
CATEGORIES=	math

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Climate analysis and downscaling for monthly and daily data
LICENSE=	gnu-gpl-v2

DEPENDS+=	R-akima>=0.5.7:../../math/R-akima
DEPENDS+=	R-ncdf>=1.6.6:../../math/R-ncdf

USE_LANGUAGES=	# none

post-extract:
	${ECHO} 'exportPattern(".")' > ${WRKSRC}/NAMESPACE

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
