# $NetBSD: options.mk,v 1.1 2023/06/26 11:46:13 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.keepassxc
PKG_SUPPORTED_OPTIONS=		yubikey
PKG_SUGGESTED_OPTIONS=		#

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Myubikey)
CMAKE_ARGS+=	-DWITH_XC_YUBIKEY=ON
.include "../../devel/libusb1/buildlink3.mk"
.include "../../security/pcsc-lite/buildlink3.mk"
.else
CMAKE_ARGS+=	-DWITH_XC_YUBIKEY=OFF
.endif
