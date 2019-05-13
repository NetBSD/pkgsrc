# $NetBSD: options.mk,v 1.2 2019/05/13 08:32:56 khorben Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.bitcoin
PKG_SUPPORTED_OPTIONS+=		qt5 miniupnpc
# qt5 is off because it doubles the footprint of the package.
# Please do not enable it by default; instead, create a split
# package.
PKG_SUGGESTED_OPTIONS+=

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mqt5)
PLIST.qt=	yes

.include "../../converters/qrencode/buildlink3.mk"
.include "../../devel/protobuf/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"

CONFIGURE_ARGS+=	--with-qt-bindir=${QTDIR}/bin
.endif

.if !empty(PKG_OPTIONS:Mminiupnpc)
.include "../../net/miniupnpc/buildlink3.mk"
.endif
