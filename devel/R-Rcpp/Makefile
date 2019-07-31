# $NetBSD: Makefile,v 1.13 2019/07/31 15:00:16 brook Exp $

CATEGORIES=	devel R

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/Rcpp/
COMMENT=	Seamless R and C++ integration
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

R_PKGNAME=	Rcpp
R_PKGVER=	1.0.2

USE_LANGUAGES+=	c++

REPLACE_R+=		inst/examples/*/*.r
REPLACE_R+=		inst/examples/SugarPerformance/sugarBenchmarks.R
REPLACE_R+=		inst/unitTests/runit.Date.R

REPLACE_RSCRIPT+=	inst/discovery/cxx0x.R

REPLACE_SH+=		inst/examples/ConvolveBenchmarks/buildAndRun.sh
REPLACE_SH+=		inst/examples/ConvolveBenchmarks/overhead.sh

REPLACE_INTERPRETER+=	R
REPLACE.R.old=		/usr/bin/env r
REPLACE.R.new=		${PREFIX}/bin/R
REPLACE_FILES.R=	${REPLACE_R}

REPLACE_INTERPRETER+=	Rscript
REPLACE.Rscript.old=	.*Rscript
REPLACE.Rscript.new=	${PREFIX}/bin/Rscript
REPLACE_FILES.Rscript=	${REPLACE_RSCRIPT}

CHECK_SSP_SKIP+=	lib/R/library/Rcpp/unitTests/bin/*/*.deb

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
