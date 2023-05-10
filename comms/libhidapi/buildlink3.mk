# $NetBSD: buildlink3.mk,v 1.3 2023/05/10 20:15:10 nikita Exp $

BUILDLINK_TREE+=	libhidapi

.if !defined(LIBHIDAPI_BUILDLINK3_MK)
LIBHIDAPI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libhidapi+=	libhidapi>=0.7.0
BUILDLINK_PKGSRCDIR.libhidapi?=	../../comms/libhidapi
.include "../../devel/libusb1/buildlink3.mk"
.if ${OPSYS} == "Linux"
.include "../../sysutils/libudev/buildlink3.mk"
.endif
.include "../../mk/pthread.buildlink3.mk"
.endif

BUILDLINK_TREE+=	-libhidapi
