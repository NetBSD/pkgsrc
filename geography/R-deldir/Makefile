# $NetBSD: Makefile,v 1.1 2020/08/07 00:20:08 brook Exp $

CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/deldir/
COMMENT=	Delaunay Triangulation and Dirichlet (Voronoi) Tessellation
LICENSE=	gnu-gpl-v2

R_PKGNAME=	deldir
R_PKGVER=	0.1-25

USE_LANGUAGES+=	c fortran

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
