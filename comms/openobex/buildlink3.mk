# $NetBSD: buildlink3.mk,v 1.15 2018/02/10 13:53:47 khorben Exp $

BUILDLINK_TREE+=	openobex

.if !defined(OPENOBEX_BUILDLINK3_MK)
OPENOBEX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openobex+=	openobex>=1.7
BUILDLINK_PKGSRCDIR.openobex?=		../../comms/openobex

.include "../../mk/libusb.buildlink3.mk"
.endif # OPENOBEX_BUILDLINK3_MK

BUILDLINK_TREE+=	-openobex
