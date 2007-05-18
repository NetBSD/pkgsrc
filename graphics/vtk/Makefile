# $NetBSD: Makefile,v 1.9 2007/05/18 07:50:11 obache Exp $
#

PKGNAME=	vtk-${VTKDIST_VERSION}
PKGREVISION=	4

COMMENT=	Visualization toolkit

.include "../../devel/cmake/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../graphics/vtk/Makefile.vtkdist"
.include "../../mk/bsd.pkg.mk"
