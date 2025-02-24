# $NetBSD: options.mk,v 1.4 2025/02/24 17:22:44 adam Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.vtk
PKG_OPTIONS_OPTIONAL_GROUPS=	gui
PKG_OPTIONS_GROUP.gui=		qt5 qt6
PKG_SUGGESTED_OPTIONS=		qt6

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	qt
.if !empty(PKG_OPTIONS:Mqt5) || !empty(PKG_OPTIONS:Mqt6)
PLIST.qt=	yes
CMAKE_CONFIGURE_ARGS+=	-DVTK_GROUP_ENABLE_Qt=YES
CMAKE_CONFIGURE_ARGS+=	-DVTK_MODULE_ENABLE_VTK_GUISupportQt=YES
CMAKE_CONFIGURE_ARGS+=	-DVTK_MODULE_ENABLE_VTK_GUISupportQtSQL=NO
CMAKE_CONFIGURE_ARGS+=	-DVTK_MODULE_ENABLE_VTK_RenderingQt=YES
CMAKE_CONFIGURE_ARGS+=	-DVTK_MODULE_ENABLE_VTK_ViewsQt=YES
.  if !empty(PKG_OPTIONS:Mqt5)
CMAKE_CONFIGURE_ARGS+=	-DVTK_QT_VERSION=5
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.  elif !empty(PKG_OPTIONS:Mqt6)
CMAKE_CONFIGURE_ARGS+=	-DVTK_QT_VERSION=6
.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.  endif
.else
CMAKE_CONFIGURE_ARGS+=	-DVTK_GROUP_ENABLE_Qt=NO
.endif
