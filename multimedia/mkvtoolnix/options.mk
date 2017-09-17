# $NetBSD: options.mk,v 1.3 2017/09/17 12:00:41 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mkvtoolnix
PKG_SUPPORTED_OPTIONS=	qt5

.include "../../mk/bsd.options.mk"

PLIST_SRC=		${PLIST_SRC_DFLT}

.if !empty(PKG_OPTIONS:Mqt5)
PLIST_SRC+=		PLIST.gui
CONFIGURE_ARGS+=	--enable-qt
CONFIGURE_ARGS+=	--with-moc=${QTDIR}/bin/moc
CONFIGURE_ARGS+=	--with-qmake=${QTDIR}/bin/qmake
CONFIGURE_ARGS+=	--with-rcc=${QTDIR}/bin/rcc
CONFIGURE_ARGS+=	--with-uic=${QTDIR}/bin/uic
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/qt5-qtmultimedia/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-qt
.endif
