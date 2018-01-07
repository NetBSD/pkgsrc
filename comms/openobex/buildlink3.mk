# $NetBSD: buildlink3.mk,v 1.14 2018/01/07 13:03:58 rillig Exp $

BUILDLINK_TREE+=	openobex

.if !defined(OPENOBEX_BUILDLINK3_MK)
OPENOBEX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openobex+=	openobex>=1.7
BUILDLINK_PKGSRCDIR.openobex?=		../../comms/openobex

.include "../../devel/libusb/buildlink3.mk"
.endif # OPENOBEX_BUILDLINK3_MK

BUILDLINK_TREE+=	-openobex
