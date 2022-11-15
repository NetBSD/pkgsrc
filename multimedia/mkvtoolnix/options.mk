# $NetBSD: options.mk,v 1.9 2022/11/15 08:55:30 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mkvtoolnix
PKG_SUPPORTED_OPTIONS=	doc gui
PKG_SUGGESTED_OPTIONS=	doc

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	doc gui

.if !empty(PKG_OPTIONS:Mgui)
PLIST.gui=		yes
CONFIGURE_ARGS+=	--enable-gui
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-gui
.endif

.if !empty(PKG_OPTIONS:Mdoc)
PLIST.doc=		yes
CONFIGURE_ARGS+=	--with-po4a=${PREFIX}/bin/po4a
BUILD_DEPENDS+=		po4a-[0-9]*:../../textproc/po4a
.else
CONFIGURE_ARGS+=	--without-po4a
.endif
