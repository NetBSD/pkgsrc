# $NetBSD: Makefile,v 1.10 2023/06/02 12:39:11 mef Exp $

R_PKGNAME=	pillar
R_PKGVER=	1.9.0
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
#   'debugme', 'DiagrammeR', 'formattable', 'nanotime', 'nycflights13',
#   'palmerpenguins', 'vdiffr'

TEST_DEPENDS+=	R-dplyr-[0-9]*:../../math/R-dplyr
TEST_DEPENDS+=	R-ggplot2-[0-9]*:../../graphics/R-ggplot2
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat
TEST_DEPENDS+=	R-units-[0-9]*:../../math/R-units


USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
