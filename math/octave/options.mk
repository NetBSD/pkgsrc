# $NetBSD: options.mk,v 1.8 2024/03/24 12:46:23 adam Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.octave
PKG_SUPPORTED_OPTIONS=		glpk graphicsmagick hdf5 qhull
PKG_OPTIONS_REQUIRED_GROUPS=	gui
PKG_OPTIONS_GROUP.gui=		qt5 qt6
PKG_SUGGESTED_OPTIONS=		hdf5 glpk qhull qt6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mglpk)
.include "../../math/glpk/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-glpk
.endif

.if !empty(PKG_OPTIONS:Mgraphicsmagick)
.include "../../graphics/GraphicsMagick/buildlink3.mk"
.else
CONFIGURE_ENV+=		ac_cv_prog_MAGICK_CONFIG=no
.endif

.if !empty(PKG_OPTIONS:Mhdf5)
.include "../../devel/hdf5/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-hdf5
.endif

.if !empty(PKG_OPTIONS:Mqhull)
.include "../../math/qhull/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-qhull
.endif

.if !empty(PKG_OPTIONS:Mqt5)
CONFIGURE_ARGS+=	--with-qt=5
.include "../../x11/qt5-qscintilla/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mqt6)
CONFIGURE_ARGS+=	--with-qt=6
.include "../../devel/qt6-qt5compat/buildlink3.mk"
.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../x11/qt6-qscintilla/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif
