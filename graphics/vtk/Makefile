# $NetBSD: Makefile,v 1.3 2004/10/03 00:14:58 tv Exp $
#

PKGNAME=	vtk-${VTKDIST_VERSION}
PKGREVISION=	1

COMMENT=	Visualization toolkit

USE_X11=	yes

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/vtk/Makefile.vtkdist"
.include "../../mk/bsd.pkg.mk"
