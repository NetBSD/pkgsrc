# $NetBSD: buildlink3.mk,v 1.6 2026/11/06 14:12:53 adam Exp $

BUILDLINK_TREE+=	libhidapi

.if !defined(LIBHIDAPI_BUILDLINK3_MK)
LIBHIDAPI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libhidapi+=	libhidapi>=0.13.1
BUILDLINK_ABI_DEPENDS.libhidapi+=	libhidapi>=0.13.1
BUILDLINK_PKGSRCDIR.libhidapi?=		../../comms/libhidapi

.include "../../devel/libusb1/buildlink3.mk"
.include "../../mk/bsd.fast.prefs.mk"
.if ${OPSYS} == "Linux"
.include "../../sysutils/libudev/buildlink3.mk"
.endif
.include "../../mk/pthread.buildlink3.mk"
.endif

BUILDLINK_TREE+=	-libhidapi
