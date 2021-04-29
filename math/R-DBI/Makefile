# $NetBSD: Makefile,v 1.10 2021/04/29 05:56:34 wen Exp $

R_PKGNAME=	DBI
R_PKGVER=	1.1.1
CATEGORIES=	math

MAINTAINER=	minskim@NetBSD.org
COMMENT=	R database interface
LICENSE=	gnu-lgpl-v2 OR gnu-lgpl-v2.1 OR gnu-lgpl-v3

TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
