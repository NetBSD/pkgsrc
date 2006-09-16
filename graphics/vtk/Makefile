# $NetBSD: Makefile,v 1.6 2006/09/16 19:37:51 rillig Exp $
#

PKGNAME=	vtk-${VTKDIST_VERSION}
PKGREVISION=	2

COMMENT=	Visualization toolkit

.include "../../devel/cmake/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../graphics/vtk/Makefile.vtkdist"
.include "../../mk/bsd.pkg.mk"
