# $NetBSD: buildlink3.mk,v 1.12 2009/08/07 12:18:33 plunky Exp $

BUILDLINK_TREE+=	openobex

.if !defined(OPENOBEX_BUILDLINK3_MK)
OPENOBEX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openobex+=	openobex>=1.5
BUILDLINK_PKGSRCDIR.openobex?=	../../comms/openobex

.include "../../devel/libusb/buildlink3.mk"
.endif # OPENOBEX_BUILDLINK3_MK

BUILDLINK_TREE+=	-openobex
