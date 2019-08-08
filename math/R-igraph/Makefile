# $NetBSD: Makefile,v 1.4 2019/08/08 19:53:50 brook Exp $

R_PKGNAME=	igraph
R_PKGVER=	1.2.4.1
CATEGORIES=	math graphics

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Network analysis and visualization
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-magrittr>=1.5:../../devel/R-magrittr
DEPENDS+=	R-pkgconfig>=2.0.0:../../devel/R-pkgconfig

USE_LANGUAGES=	c c++ fortran

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
