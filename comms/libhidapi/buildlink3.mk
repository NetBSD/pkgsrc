# $NetBSD: buildlink3.mk,v 1.1 2015/04/03 22:29:12 rodent Exp $

BUILDLINK_TREE+=	libhidapi

.if !defined(LIBHIDAPI_BUILDLINK3_MK)
LIBHIDAPI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libhidapi+=	libhidapi>=0.7.0
BUILDLINK_PKGSRCDIR.libhidapi?=	../../comms/libhidapi
.endif

BUILDLINK_TREE+=	-libhidapi
