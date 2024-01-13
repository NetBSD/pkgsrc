# $NetBSD: Makefile,v 1.3 2024/01/13 22:51:39 mef Exp $

R_PKGNAME=	spatstat.data
R_PKGVER=	3.0-3
CATEGORIES=	geography

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Datasets for 'spatstat'
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-spatstat.utils>=3.0.3:../../geography/R-spatstat.utils

TEST_DEPENDS+=	R-spatstat.linnet>=2.0.0:../../geography/R-spatstat.linnet

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
