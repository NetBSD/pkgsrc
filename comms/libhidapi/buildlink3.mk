# $NetBSD: buildlink3.mk,v 1.4 2023/05/17 14:58:30 nikita Exp $

BUILDLINK_TREE+=	libhidapi

.if !defined(LIBHIDAPI_BUILDLINK3_MK)
LIBHIDAPI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libhidapi+=	libhidapi>=0.13.1
BUILDLINK_ABPI_DEPENDS.libhidapi+=	libhidapi>=0.13.1
BUILDLINK_PKGSRCDIR.libhidapi?=	../../comms/libhidapi
.include "../../devel/libusb1/buildlink3.mk"
.if ${OPSYS} == "Linux"
.include "../../sysutils/libudev/buildlink3.mk"
.endif
.include "../../mk/pthread.buildlink3.mk"
.endif

BUILDLINK_TREE+=	-libhidapi
