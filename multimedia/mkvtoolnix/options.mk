# $NetBSD: options.mk,v 1.2 2016/09/08 16:18:01 joerg Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mkvtoolnix
PKG_SUPPORTED_OPTIONS=	gui
PKG_SUGGESTED_OPTIONS=	# empty

.include "../../mk/bsd.options.mk"

PLIST_SRC=		${PLIST_SRC_DFLT}

.if !empty(PKG_OPTIONS:Mgui)
PLIST_SRC+=		PLIST.gui
CONFIGURE_ARGS+=	--enable-qt MOC=${QTDIR}/bin/moc
CONFIGURE_ARGS+=	UIC=${QTDIR}/bin/uic RCC=${QTDIR}/bin/rcc
USE_TOOLS+=		pkg-config
.include "../../x11/qt5-qtbase/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-qt
.endif
