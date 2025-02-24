# $NetBSD: options.mk,v 1.5 2025/02/24 17:22:56 adam Exp $
PKG_OPTIONS_VAR=	PKG_OPTIONS.pcl

# Qt could be an option, but relies on vtk's qt support, too.
# Maybe vtk will always include Qt and then we will bundle it
# here, too.
PKG_SUPPORTED_OPTIONS=	vtk
PKG_SUGGESTED_OPTIONS=	vtk

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	qt vtk x11

.if !empty(PKG_OPTIONS:Mvtk)
CMAKE_CONFIGURE_ARGS+=	-DWITH_VTK=TRUE
PLIST.vtk=	yes
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/vtk/buildlink3.mk"
.  if ${PKG_BUILD_OPTIONS.vtk:Mqt5}
CMAKE_CONFIGURE_ARGS+=	-DWITH_QT=QT5
CMAKE_CONFIGURE_ARGS+=	-DBUILD_apps=ON
PLIST.qt=	yes
.  elif ${PKG_BUILD_OPTIONS.vtk:Mqt6}
CMAKE_CONFIGURE_ARGS+=	-DWITH_QT=QT6
CMAKE_CONFIGURE_ARGS+=	-DBUILD_apps=ON
PLIST.qt=	yes
.  endif
.  if ${OPSYS} != "Darwin"
PLIST.x11=	yes
.  endif
.else
CMAKE_CONFIGURE_ARGS+=	-DWITH_QT=NO
CMAKE_CONFIGURE_ARGS+=	-DWITH_VTK=FALSE
.endif
