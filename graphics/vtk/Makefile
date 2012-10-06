# $NetBSD: Makefile,v 1.12 2012/10/06 14:11:24 asau Exp $
#

PKGNAME=	vtk-${VTKDIST_VERSION}
PKGREVISION=	5

COMMENT=	Visualization toolkit

.include "../../devel/cmake/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../graphics/vtk/Makefile.vtkdist"
.include "../../mk/bsd.pkg.mk"
