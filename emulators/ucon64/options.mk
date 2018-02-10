# $NetBSD: options.mk,v 1.2 2018/02/10 13:53:48 khorben Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ucon64
PKG_SUPPORTED_OPTIONS=	libusb

.include "../../mk/bsd.options.mk"

###
### Build with USB support.
###
.if !empty(PKG_OPTIONS:Mlibusb)
CONFIGURE_ARGS+=	--with-libusb
CPPFLAGS+=		-I${BUILDLINK_PREFIX.libusb}/include
LDFLAGS+=		-L${BUILDLINK_PREFIX.libusb}/lib
LDFLAGS+=		${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libusb}/lib
.  include "../../mk/libusb.buildlink3.mk"
.endif
