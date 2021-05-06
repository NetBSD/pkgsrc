# $NetBSD: options.mk,v 1.4 2021/05/06 15:31:13 tnn Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.openocd
PKG_SUPPORTED_OPTIONS=	libhidapi libusb libusb1 libftdi1 capstone
PKG_SUGGESTED_OPTIONS+=	${PKG_SUPPORTED_OPTIONS}
PLIST_VARS+=		libusb1

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlibhidapi)
.include "../../comms/libhidapi/buildlink3.mk"
HIDAPI_CFLAGS=		-I${BUILDLINK_PREFIX.libhidapi}/include/hidapi
HIDAPI_LIBS=		-L${BUILDLINK_PREFIX.libhidapi}/lib \
			${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libhidapi}/lib \
			-lhidapi
CONFIGURE_ENV+=		HIDAPI_CFLAGS=${HIDAPI_CFLAGS:Q}
CONFIGURE_ENV+=		HIDAPI_LIBS=${HIDAPI_LIBS:Q}
.endif

.if !empty(PKG_OPTIONS:Mlibusb)
.include "../../mk/libusb.buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mlibusb1)
.include "../../devel/libusb1/buildlink3.mk"
PLIST.libusb1=		yes
.endif

.if !empty(PKG_OPTIONS:Mlibftdi1)
.include "../../devel/libftdi1/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mcapstone)
.include "../../devel/capstone/buildlink3.mk"
.endif
