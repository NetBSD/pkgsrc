# $NetBSD: Makefile,v 1.23 2021/08/21 13:37:31 mef Exp $

R_PKGNAME=	Rcpp
R_PKGVER=	1.0.7
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Seamless R and C++ integration
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

TEST_DEPENDS+=	R-RUnit-[0-9]*:../../devel/R-RUnit
TEST_DEPENDS+=	R-inline-[0-9]*:../../devel/R-inline
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-markdown-[0-9]*:../../textproc/R-markdown
TEST_DEPENDS+=	R-pkgKitten>=0.1.2:../../devel/R-pkgKitten
TEST_DEPENDS+=	R-rbenchmark>=1.0.0:../../benchmarks/R-rbenchmark
TEST_DEPENDS+=	R-tinytest-[0-9]*:../../devel/R-tinytest
TEST_DEPENDS+=	tex-pdfpages-[0-9]*:../../print/tex-pdfpages
TEST_DEPENDS+=	tex-fancyvrb-[0-9]*:../../print/tex-fancyvrb
TEST_DEPENDS+=	tex-iftex-[0-9]*d:../../print/tex-iftex
TEST_DEPENDS+=	tex-pdflscape-[0-9]*:../../print/tex-pdflscape
TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec

USE_LANGUAGES+=	c++

REPLACE_R+=		inst/examples/*/*.r
REPLACE_R+=		inst/examples/SugarPerformance/sugarBenchmarks.R

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

CHECK_SSP_SKIP+=	lib/R/library/Rcpp/*/bin/*/*.deb
CHECK_RELRO_SKIP+=	${CHECK_SSP_SKIP}

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
