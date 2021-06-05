# $NetBSD: Makefile,v 1.5 2021/06/05 08:30:23 mef Exp $

R_PKGNAME=	tibble
R_PKGVER=	3.1.2
#ATEGORIES=	math

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Simple data frames
LICENSE=	mit

DEPENDS+=	R-cli>=1.1.0:../../devel/R-cli
DEPENDS+=	R-crayon>=1.3.4:../../devel/R-crayon
DEPENDS+=	R-fansi>=0.4.0:../../devel/R-fansi
DEPENDS+=	R-pkgconfig>=2.0.2:../../devel/R-pkgconfig
DEPENDS+=	R-rlang>=0.3.0:../../devel/R-rlang
DEPENDS+=	R-pillar>=1.3.1:../../misc/R-pillar

#Packages suggested but not available:
#  'bench', 'bit64', 'blob', 'DiagrammeR', 'dplyr', 'formattable',
#  'ggplot2', 'hms', 'lubridate', 'mockr', 'nycflights13', 'purrr',
#  'testthat', 'tidyr'

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
