# $NetBSD: Makefile,v 1.3 2019/07/31 19:47:01 brook Exp $

CATEGORIES=	math graphics R

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://igraph.org/
COMMENT=	Network analysis and visualization
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

R_PKGNAME=	igraph
R_PKGVER=	1.2.4.1

DEPENDS+=	R-magrittr>=1.5:../../devel/R-magrittr
DEPENDS+=	R-pkgconfig>=2.0.0:../../devel/R-pkgconfig

USE_LANGUAGES=	c c++ fortran

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
