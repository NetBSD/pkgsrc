# $NetBSD: Makefile,v 1.9 2020/09/20 22:51:47 mef Exp $

R_PKGNAME=	DBI
R_PKGVER=	1.1.0
CATEGORIES=	math

MAINTAINER=	minskim@NetBSD.org
COMMENT=	R database interface
LICENSE=	gnu-lgpl-v2 OR gnu-lgpl-v2.1 OR gnu-lgpl-v3

TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
