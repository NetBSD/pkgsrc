# $NetBSD: Makefile,v 1.1 2022/05/30 14:54:19 mef Exp $

R_PKGNAME=	profmem
R_PKGVER=	0.6.0
CATEGORIES=	benchmarks

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Simple Memory Profiling for R
LICENSE=	gnu-lgpl-v2.1

TEST_DEPENDS+=	R-microbenchmark-[0-9]*:../../benchmarks/R-microbenchmark
#EST_DEPENDS+=	R-R.rsp-[0-9]*:

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
