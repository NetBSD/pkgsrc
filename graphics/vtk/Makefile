# $NetBSD: Makefile,v 1.2 2004/09/10 11:21:24 drochner Exp $
#

PKGNAME=	vtk-${VTKDIST_VERSION}

COMMENT=	Visualization toolkit

USE_X11=	yes

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/vtk/Makefile.vtkdist"
.include "../../mk/bsd.pkg.mk"
