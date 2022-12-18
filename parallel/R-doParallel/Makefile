# $NetBSD: Makefile,v 1.1 2022/12/18 12:46:19 mef Exp $

R_PKGNAME=	doParallel
R_PKGVER=	1.0.17
CATEGORIES=	parallel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Foreach Parallel Adaptor for the 'parallel' Package
LICENSE=	gnu-gpl-v2

DEPENDS+=	R-foreach>=1.2.0:../../devel/R-foreach
DEPENDS+=	R-iterators>=1.0.0:../../devel/R-iterators

# Packages suggested but not available: 'caret', 'mlbench'
TEST_DEPENDS+=	R-RUnit-[0-9]*:../../devel/R-RUnit

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
