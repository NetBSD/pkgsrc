# $NetBSD: Makefile,v 1.1 2021/09/09 22:12:14 mef Exp $

R_PKGNAME=	vroom
R_PKGVER=	1.5.4
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Read and Write Rectangular Text Data Quickly
LICENSE=	mit	# + file LICENSE

DEPENDS+=	R-bit64>=4.0.5:../../devel/R-bit64
DEPENDS+=	R-cli>=2.5.0:../../devel/R-cli
DEPENDS+=	R-crayon>=1.3.4:../../devel/R-crayon
DEPENDS+=	R-glue>=1.4.2:../../devel/R-glue
DEPENDS+=	R-lifecycle>=1.0.0:../../devel/R-lifecycle
DEPENDS+=	R-rlang>=0.4.2:../../devel/R-rlang
DEPENDS+=	R-tidyselect>=1.1.1:../../devel/R-tidyselect
DEPENDS+=	R-withr>=2.4.2:../../devel/R-withr
DEPENDS+=	R-tibble>=2.0.0:../../math/R-tibble
DEPENDS+=	R-vctrs>=0.2.0:../../math/R-vctrs
DEPENDS+=	R-hms>=1.1.0:../../time/R-hms
DEPENDS+=	R-progress-[0-9]*:../../sysutils/R-progress
DEPENDS+=	R-tzdb-[0-9]*:../../time/R-tzdb

USE_LANGUAGES=	c c++11

REPLACE_BASH+=	inst/bench/download-data.sh inst/bench/script.sh
REPLACE_R+=	inst/bench/session_info.R inst/bench/run-bench.R inst/bench/run-bench-fwf.R

.include "../../lang/R-cpp11/buildlink3.mk"
.include "../../time/R-tzdb/buildlink3.mk"
.include "../../sysutils/R-progress/buildlink3.mk"

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
