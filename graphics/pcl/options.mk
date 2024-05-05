# $NetBSD: options.mk,v 1.3 2024/05/05 20:58:06 adam Exp $
PKG_OPTIONS_VAR=	PKG_OPTIONS.pcl

# Qt could be an option, but relies on vtk's qt support, too.
# Maybe vtk will always include Qt and then we will bundle it
# here, too.
PKG_SUPPORTED_OPTIONS=	vtk
PKG_SUGGESTED_OPTIONS=	vtk

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	vtk qt
.if !empty(PKG_OPTIONS:Mvtk)

CMAKE_ARGS+=	-DWITH_VTK=TRUE
PLIST.vtk=	yes
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/vtk/buildlink3.mk"
.  if ${PKG_BUILD_OPTIONS.vtk:Mqt}
CMAKE_ARGS+=	-DWITH_QT=QT5
CMAKE_ARGS+=	-DBUILD_apps=ON
PLIST.qt=	yes
.include "../../x11/qt5-qtbase/buildlink3.mk"
.  endif
.else
CMAKE_ARGS+=	-DWITH_VTK=FALSE
CMAKE_ARGS+=    -DWITH_QT=NO
.endif
