# $NetBSD: options.mk,v 1.1.1.1 2009/02/26 10:07:49 hasso Exp $

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
.include "../../devel/libusb/buildlink3.mk"
CONFIGURE_ARGS+=        --enable-usb
.else
CONFIGURE_ARGS+=        --disable-usb
.endif
