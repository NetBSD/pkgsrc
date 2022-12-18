# $NetBSD: Makefile,v 1.1 2022/12/18 09:25:00 mef Exp $

R_PKGNAME=	profvis
R_PKGVER=	0.3.7
CATEGORIES=	benchmarks

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Interactive Visualizations for Profiling R Code
LICENSE=	gnu-gpl-v3 # See more for LICENSE file

DEPENDS+=	R-stringr>=1.4.0:../../textproc/R-stringr
DEPENDS+=	R-htmlwidgets>=0.3.2:../../www/R-htmlwidgets

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
