# $NetBSD: options.mk,v 1.1 2011/03/20 13:19:44 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mkvtoolnix
PKG_SUPPORTED_OPTIONS=	# empty
PKG_OPTIONS_OPTIONAL_GROUPS=	gui
PKG_OPTIONS_GROUP.gui=	wxwidgets
PKG_SUGGESTED_OPTIONS=	# empty

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		gui

.if !empty(PKG_OPTIONS:Mqt) || !empty(PKG_OPTIONS:Mwxwidgets)
PLIST.gui=		yes
CONFIGURE_ARGS+=	--enable-gui
.else
CONFIGURE_ARGS+=	--disable-gui
.endif

#.if !empty(PKG_OPTIONS:Mqt)
#CONFIGURE_ARGS+=	--enable-qt
#.  include "../../x11/qt4-libs/buildlink3.mk"
#.  include "../../x11/qt4-tools/buildlink3.mk"
#.else
#CONFIGURE_ARGS+=	--disable-qt
#.endif

.if !empty(PKG_OPTIONS:Mwxwidgets)
CONFIGURE_ARGS+=	--enable-wxwidgets
.  include "../../databases/shared-mime-info/mimedb.mk"
.  include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.  include "../../sysutils/desktop-file-utils/desktopdb.mk"
.  include "../../x11/wxGTK28/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-wxwidgets
.endif
