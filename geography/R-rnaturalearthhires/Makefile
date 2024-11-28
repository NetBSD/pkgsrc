# $NetBSD: Makefile,v 1.2 2024/11/28 14:13:38 mef Exp $

# This is an R package but not from CRAN.  Therefore, it does not
# entirely follow the normal structure of an R package.

GITHUB_PROJECT=	rnaturalearthhires
GITHUB_TAG=	7a3f0fc8d8d690fae044dd01eb2f14d3a75c92ed
DISTNAME=	7a3f0fc8d8d690fae044dd01eb2f14d3a75c92ed

R_PKGNAME=	rnaturalearthhires
R_PKGVER=	1.0.0

CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_GITHUB:=ropensci/}
EXTRACT_SUFX=	.zip
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ropensci/rnaturalearthhires/
COMMENT=	High Resolution World Vector Map Data from Natural Earth
LICENSE=	cc0-1.0-universal

WRKSRC=		${WRKDIR}/rnaturalearthhires-7a3f0fc8d8d690fae044dd01eb2f14d3a75c92ed
USE_LANGUAGES=	# none

DEPENDS+=	R-sp>=1.0.15:../../math/R-sp

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
