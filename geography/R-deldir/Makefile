# $NetBSD: Makefile,v 1.6 2024/11/26 13:42:18 mef Exp $

CATEGORIES=	geography

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/deldir/
COMMENT=	Delaunay Triangulation and Dirichlet (Voronoi) Tessellation
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

R_PKGNAME=	deldir
R_PKGVER=	2.0-4

TEST_DEPENDS+=	R-polyclip-[0-9]*:../../graphics/R-polyclip

TEST_DEPENDS+=	tex-cm-super-[0-9]*:../../fonts/tex-cm-super
TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

USE_LANGUAGES+=	c fortran

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
