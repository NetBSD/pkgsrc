# $NetBSD: options.mk,v 1.1 2026/11/09 10:45:17 nros Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.TeXmacs
PKG_SUPPORTED_OPTIONS=		debug
PKG_OPTIONS_REQUIRED_GROUPS=	qt
PKG_OPTIONS_GROUP.qt=		qt5 qt6
PKG_SUGGESTED_OPTIONS=		qt5
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_BUILD_TYPE=Debug
.endif

.if !empty(PKG_OPTIONS:Mqt5)
CMAKE_CONFIGURE_ARGS+=	-DTEXMACS_GUI=Qt5
.  include "../../x11/qt5-qtbase/buildlink3.mk"
.  if ${OPSYS} == "Darwin"
.    include "../../x11/qt5-qtmacextras/buildlink3.mk"
.  endif
.  include "../../x11/qt5-qtsvg/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mqt6)
CMAKE_CONFIGURE_ARGS+=	-DTEXMACS_GUI=Qt6
.  include "../../devel/qt6-qt5compat/buildlink3.mk"
.  include "../../graphics/qt6-qtsvg/buildlink3.mk"
.  include "../../x11/qt6-qtbase/buildlink3.mk"
# the qt6 version can crash if the locale is not C
# when compiled using gcc on non-gnu systems
.  include "../../mk/compiler.mk"
.  if ${OPSYS} != "Linux" && !empty(CC_VERSION:Mgcc-*)
SUBST_CLASSES+=		locale
SUBST_STAGE.locale=	pre-configure
SUBST_FILES.locale=	misc/scripts/texmacs.in
SUBST_SED.locale=	-e 's,exec,export LC_ALL=C \&\& exec,1'
.  endif
.endif
