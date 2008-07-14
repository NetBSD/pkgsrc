# $NetBSD: Makefile,v 1.11 2008/07/14 12:56:05 joerg Exp $
#

PKGNAME=	vtk-${VTKDIST_VERSION}
PKGREVISION=	5

PKG_DESTDIR_SUPPORT=	user-destdir

COMMENT=	Visualization toolkit

.include "../../devel/cmake/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../graphics/vtk/Makefile.vtkdist"
.include "../../mk/bsd.pkg.mk"
