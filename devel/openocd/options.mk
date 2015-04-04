# $NetBSD: options.mk,v 1.1 2015/04/04 00:26:42 rodent Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.openocd
PKG_SUPPORTED_OPTIONS=	libhidapi libusb libusb1
PKG_SUGGESTED_OPTIONS+=	${PKG_SUPPORTED_OPTIONS}
PLIST_VARS+=		libusb1

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlibhidapi)
.include "../../comms/libhidapi/buildlink3.mk"
HIDAPI_CFLAGS=		-I${BUILDLINK_PREFIX.libhidapi}/include/hidapi
HIDAPI_LIBS=		-L/usr/pkgsrc/pkg/lib -Wl,-R/usr/pkgsrc/pkg/lib -lhidapi
CONFIGURE_ENV+=		HIDAPI_CFLAGS=${HIDAPI_CFLAGS:Q}
CONFIGURE_ENV+=		HIDAPI_LIBS=${HIDAPI_LIBS:Q}
.endif

.if !empty(PKG_OPTIONS:Mlibusb)
.include "../../devel/libusb/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mlibusb1)
.include "../../devel/libusb1/buildlink3.mk"
PLIST.libusb1=		yes
.endif
