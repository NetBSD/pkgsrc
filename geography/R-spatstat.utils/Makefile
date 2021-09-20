# $NetBSD: Makefile,v 1.2 2021/09/20 07:21:52 mef Exp $

R_PKGNAME=	spatstat.utils
R_PKGVER=	2.2-0
CATEGORIES=	geography

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Utility Functions for 'spatstat'
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

# ERROR: dependencies 'spatstat.data', 'spatstat.geom', 'spatstat.sparse', 'abind', 'tensor', 'goftest' are not available

TEST_DEPENDS+=	R-spatstat.core-[0-9]*:../../geography/R-spatstat.core

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
