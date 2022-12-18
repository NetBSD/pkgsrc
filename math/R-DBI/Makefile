# $NetBSD: Makefile,v 1.11 2022/12/18 06:46:43 mef Exp $

R_PKGNAME=	DBI
R_PKGVER=	1.1.3

MAINTAINER=	minskim@NetBSD.org
COMMENT=	R database interface
LICENSE=	gnu-lgpl-v2 OR gnu-lgpl-v2.1 OR gnu-lgpl-v3

# Packages suggested but not available: 'DBItest', 'RMariaDB'

TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
