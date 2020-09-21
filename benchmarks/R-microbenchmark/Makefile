# $NetBSD: Makefile,v 1.1 2020/09/21 00:25:18 mef Exp $

R_PKGNAME=	microbenchmark
R_PKGVER=	1.4-7
CATEGORIES=	benchmarks

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Accurate Timing Functions
LICENSE=	2-clause-bsd	# + file LICENSE

# Packages suggested but not available: 'multcomp', 'RUnit'
TEST_DEPENDS+=	R-RUnit-[0-9]*:../../devel/R-RUnit


USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
