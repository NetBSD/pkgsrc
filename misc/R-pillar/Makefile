# $NetBSD: Makefile,v 1.11 2025/01/29 11:27:50 mef Exp $

R_PKGNAME=	pillar
R_PKGVER=	1.10.1
CATEGORIES=	misc

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Coloured formatting for columns
LICENSE=	gnu-gpl-v3

DEPENDS+=	R-cli>=2.3.0:../../devel/R-cli
DEPENDS+=	R-crayon>=1.3.4:../../devel/R-crayon
DEPENDS+=	R-fansi>=0.4.0:../../devel/R-fansi
DEPENDS+=	R-rlang>=0.3.0:../../devel/R-rlang
DEPENDS+=	R-vctrs>=0.5.0:../../math/R-vctrs
DEPENDS+=	R-utf8>=1.1.0:../../textproc/R-utf8
DEPENDS+=	R-lifecycle-[0-9]*:../../devel/R-lifecycle

# Packages suggested but not available:
#   'DiagrammeR', 'formattable', 'nycflights13', 'palmerpenguins',
#   'vdiffr'

TEST_DEPENDS+=	R-DBI-[0-9]*:../../math/R-DBI
TEST_DEPENDS+=	R-bit64-[0-9]*:../../devel/R-bit64
TEST_DEPENDS+=	R-debugme-[0-9]*:../../devel/R-debugme
TEST_DEPENDS+=	R-dplyr-[0-9]*:../../math/R-dplyr
TEST_DEPENDS+=	R-ggplot2-[0-9]*:../../graphics/R-ggplot2
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-lubridate-[0-9]*:../../time/R-lubridate
TEST_DEPENDS+=	R-nanotime-[0-9]*:../../time/R-nanotime
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat
TEST_DEPENDS+=	R-units-[0-9]*:../../math/R-units


USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
