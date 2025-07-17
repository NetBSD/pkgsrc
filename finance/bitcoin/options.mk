# $NetBSD: options.mk,v 1.4 2025/07/17 11:22:59 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.bitcoin
PKG_SUPPORTED_OPTIONS+=	qt5
# qt5 is off because it doubles the footprint of the package.
# Please do not enable it by default; instead, create a split
# package.

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	qt

.if !empty(PKG_OPTIONS:Mqt5)
CMAKE_CONFIGURE_ARGS+=	-DBUILD_GUI=ON
PLIST.qt=	yes
.include "../../converters/qrencode/buildlink3.mk"
.include "../../devel/protobuf/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.endif
