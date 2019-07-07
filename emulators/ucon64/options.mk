# $NetBSD: options.mk,v 1.3 2019/07/07 22:47:57 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ucon64
PKG_SUPPORTED_OPTIONS=	libusb

.include "../../mk/bsd.options.mk"

###
### Build with USB support.
###
.if !empty(PKG_OPTIONS:Mlibusb)
CONFIGURE_ARGS+=	--with-libusb
.  include "../../mk/libusb.buildlink3.mk"
.endif
