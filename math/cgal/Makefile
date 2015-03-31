# $NetBSD: Makefile,v 1.26 2015/03/31 15:48:32 joerg Exp $

PKGNAME=	cgal-3.9
DISTNAME=	CGAL-3.9
PKGREVISION=	23
CATEGORIES=	math
MASTER_SITES=	https://gforge.inria.fr/frs/download.php/29125/

MAINTAINER=	reinoud@NetBSD.org
HOMEPAGE=	http://www.cgal.org/
COMMENT=	Computational Geometry Algorithms Library
LICENSE=	gnu-lgpl-v3

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

pre-install:
	cd ${WRKSRC} && rm -f include/CGAL/Mesh_2/Do_not_refine_edges.h.orig include/CGAL/config.h.orig

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
