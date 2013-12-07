# $NetBSD: Makefile,v 1.7 2013/12/07 19:32:48 dholland Exp $

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/clim.pact/
COMMENT=	Climate analysis and downscaling for monthly and daily data
LICENSE=	gnu-gpl-v2

R_PKGNAME=	clim.pact
R_PKGVER=	2.3-10

DEPENDS+=	R-akima>=0.5.7:../../math/R-akima
DEPENDS+=	R-ncdf>=1.6.6:../../math/R-ncdf

post-extract:
	echo 'exportPattern("^[^\\.]")' > ${WRKSRC}/NAMESPACE

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
