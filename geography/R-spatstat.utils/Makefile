# $NetBSD: Makefile,v 1.3 2024/01/13 22:29:14 mef Exp $

R_PKGNAME=	spatstat.utils
R_PKGVER=	3.0-4
CATEGORIES=	geography

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Utility Functions for 'spatstat'
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

TEST_DEPENDS+=	R-spatstat.core-[0-9]*:../../geography/R-spatstat.core

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
