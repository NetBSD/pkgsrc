# $NetBSD: options.mk,v 1.1 2021/05/07 11:36:29 thor Exp $
PKG_OPTIONS_VAR=	PKG_OPTIONS.pcl

# Qt could be an option, but relies on vtk's qt support, too.
# Maybe vtk will always include Qt and then we will bundle it
# here, too.
PKG_SUPPORTED_OPTIONS=	vtk
PKG_SUGGESTED_OPTIONS=	vtk

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	vtk
.if !empty(PKG_OPTIONS:Mvtk)
CMAKE_ARGS+=	-DWITH_VTK=TRUE
PLIST.vtk=	yes
.include "../../graphics/vtk/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.else
CMAKE_ARGS+=	-DWITH_VTK=FALSE	
.endif
