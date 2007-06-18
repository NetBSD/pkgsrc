# $NetBSD: Makefile,v 1.10 2007/06/18 17:58:35 joerg Exp $
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
