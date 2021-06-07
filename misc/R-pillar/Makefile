# $NetBSD: Makefile,v 1.7 2021/06/07 15:35:24 mef Exp $

R_PKGNAME=	pillar
R_PKGVER=	1.6.1
CATEGORIES=	misc

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Coloured formatting for columns
LICENSE=	gnu-gpl-v3

DEPENDS+=	R-cli>=1.1.0:../../devel/R-cli
DEPENDS+=	R-crayon>=1.3.4:../../devel/R-crayon
DEPENDS+=	R-fansi>=0.4.0:../../devel/R-fansi
DEPENDS+=	R-rlang>=0.3.0:../../devel/R-rlang
DEPENDS+=	R-vctrs>=0.2.0:../../math/R-vctrs
DEPENDS+=	R-utf8>=1.1.0:../../textproc/R-utf8
DEPENDS+=	R-utf8>=1.1.3:../../textproc/R-utf8
DEPENDS+=	R-lifecycle-[0-9]*:../../devel/R-lifecycle

# Packages suggested but not available:
#  'debugme', 'DiagrammeR','formattable', 'nycflights13',
#  'palmerpenguins'
TEST_DEPENDS+=	R-dplyr-[0-9]*:../../math/R-dplyr
TEST_DEPENDS+=	R-units-[0-9]*:../../math/R-units


USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
