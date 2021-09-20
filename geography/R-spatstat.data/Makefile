# $NetBSD: Makefile,v 1.2 2021/09/20 11:05:37 mef Exp $

R_PKGNAME=	spatstat.data
R_PKGVER=	2.1-0
CATEGORIES=	geography

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Datasets for 'spatstat'
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-spatstat.utils>=2.0.0:../../geography/R-spatstat.utils

TEST_DEPENDS+=	R-spatstat.linnet>=2.0.0:../../geography/R-spatstat.linnet

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
