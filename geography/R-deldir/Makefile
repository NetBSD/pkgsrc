# $NetBSD: Makefile,v 1.5 2023/06/15 11:20:45 mef Exp $

CATEGORIES=	geography

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/deldir/
COMMENT=	Delaunay Triangulation and Dirichlet (Voronoi) Tessellation
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

R_PKGNAME=	deldir
R_PKGVER=	1.0-9

TEST_DEPENDS+=	R-polyclip-[0-9]*:../../graphics/R-polyclip
TEST_DEPENDS+=	tex-cm-super-[0-9]*:../../fonts/tex-cm-super

USE_LANGUAGES+=	c fortran

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
