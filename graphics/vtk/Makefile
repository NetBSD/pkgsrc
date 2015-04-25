# $NetBSD: Makefile,v 1.13 2015/04/25 14:23:20 tnn Exp $
#

PKGNAME=	vtk-${VTKDIST_VERSION}
PKGREVISION=	6

COMMENT=	Visualization toolkit

.include "../../devel/cmake/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../graphics/vtk/Makefile.vtkdist"
.include "../../mk/bsd.pkg.mk"
