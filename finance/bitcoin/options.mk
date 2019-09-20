# $NetBSD: options.mk,v 1.3 2019/09/20 16:57:28 adam Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.bitcoin
PKG_SUPPORTED_OPTIONS+=		qt5 upnp
# qt5 is off because it doubles the footprint of the package.
# Please do not enable it by default; instead, create a split
# package.

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	qt

.if !empty(PKG_OPTIONS:Mqt5)
CONFIGURE_ARGS+=	--with-gui=qt5
CONFIGURE_ARGS+=	--with-qt-bindir=${QTDIR}/bin
PLIST.qt=	yes
.include "../../converters/qrencode/buildlink3.mk"
.include "../../devel/protobuf/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--with-gui=no
.endif

.if !empty(PKG_OPTIONS:Mupnp)
CONFIGURE_ARGS+=	--with-miniupnpc
.include "../../net/miniupnpc/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-miniupnpc
.endif
