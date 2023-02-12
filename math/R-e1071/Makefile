# $NetBSD: Makefile,v 1.14 2023/02/12 04:16:32 mef Exp $

R_PKGNAME=	e1071
R_PKGVER=	1.7-13

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Misc Functions of the Department of Statistics (e1071), TU Wien
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-proxy-[0-9]*:../../math/R-proxy

# Packages suggested but not available: 'mlbench', 'slam'
TEST_DEPENDS+=	R-randomForest-[0-9]*:../../math/R-randomForest
TEST_DEPENDS+=	R-SparseM-[0-9]*:../../math/R-SparseM
TEST_DEPENDS+=	R-xtable-[0-9]*:../../math/R-xtable
TEST_DEPENDS+=	R-mlbench-[0-9]*:../../benchmarks/R-mlbench

USE_LANGUAGES=	c c++

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
