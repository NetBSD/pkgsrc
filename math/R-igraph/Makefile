# $NetBSD: Makefile,v 1.13 2023/03/11 11:07:54 mef Exp $

R_PKGNAME=	igraph
R_PKGVER=	1.4.1
CATEGORIES=	math graphics

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Network analysis and visualization
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-magrittr>=1.5:../../devel/R-magrittr
DEPENDS+=	R-pkgconfig>=2.0.0:../../devel/R-pkgconfig
DEPENDS+=	R-rlang-[0-9]*:../../devel/R-rlang

USE_LANGUAGES=	c c++ fortran

.include "../../math/R/Makefile.extension"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
