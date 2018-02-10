# $NetBSD: options.mk,v 1.2 2018/02/10 13:53:48 khorben Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.openct
PKG_SUPPORTED_OPTIONS=	pcsc-lite libusb
PKG_SUGGESTED_OPTIONS=	pcsc-lite
PLIST_VARS+=		pcsc-lite

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpcsc-lite)
.include "../../security/pcsc-lite/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-pcsc
PLIST.pcsc-lite=	yes
.else
CONFIGURE_ARGS+=	--disable-pcsc
.endif

.if !empty(PKG_OPTIONS:Mlibusb)
.include "../../mk/libusb.buildlink3.mk"
CONFIGURE_ARGS+=        --enable-usb
.else
CONFIGURE_ARGS+=        --disable-usb
.endif
