# $NetBSD: buildlink3.mk,v 1.2 2015/04/04 13:18:54 rodent Exp $

BUILDLINK_TREE+=	libhidapi

.if !defined(LIBHIDAPI_BUILDLINK3_MK)
LIBHIDAPI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libhidapi+=	libhidapi>=0.7.0
BUILDLINK_PKGSRCDIR.libhidapi?=	../../comms/libhidapi
.include "../../devel/libusb1/buildlink3.mk"
.endif

BUILDLINK_TREE+=	-libhidapi
