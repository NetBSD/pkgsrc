# $NetBSD: Makefile,v 1.3 2020/09/20 21:18:13 mef Exp $

R_PKGNAME=	checkmate
R_PKGVER=	2.0.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Fast and versatile argument checks
LICENSE=	modified-bsd

DEPENDS+=	R-backports>=1.1.0:../../math/R-backports

# Packages suggested but not available:
#   'fastmatch', 'microbenchmark'

TEST_DEPENDS+=	R-data.table-[0-9]*:../../textproc/R-data.table
TEST_DEPENDS+=	R-devtools-[0-9]*:../../devel/R-devtools
TEST_DEPENDS+=	R-tinytest-[0-9]*:../../devel/R-tinytest


USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
