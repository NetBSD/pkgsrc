# $NetBSD: options.mk,v 1.7 2022/10/02 18:39:42 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mkvtoolnix
PKG_SUPPORTED_OPTIONS=	gui doc
PKG_SUGGESTED_OPTIONS=	doc

.include "../../mk/bsd.options.mk"

PLIST_SRC=		${PLIST_SRC_DFLT}

.if !empty(PKG_OPTIONS:Mgui)
PLIST_SRC+=		PLIST.gui
CONFIGURE_ARGS+=	--enable-gui
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-gui
.endif

.if !empty(PKG_OPTIONS:Mdoc)
PLIST_SRC+=		PLIST.po4a
CONFIGURE_ARGS+=	--with-po4a
BUILD_DEPENDS+=		po4a-[0-9]*:../../textproc/po4a
.else
CONFIGURE_ARGS+=	--without-po4a
.endif
