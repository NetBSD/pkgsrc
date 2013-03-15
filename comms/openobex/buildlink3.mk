# $NetBSD: buildlink3.mk,v 1.13 2013/03/15 08:10:04 plunky Exp $

BUILDLINK_TREE+=	openobex

.if !defined(OPENOBEX_BUILDLINK3_MK)
OPENOBEX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openobex+=	openobex>=1.7
BUILDLINK_PKGSRCDIR.openobex?=	../../comms/openobex

.include "../../devel/libusb/buildlink3.mk"
.endif # OPENOBEX_BUILDLINK3_MK

BUILDLINK_TREE+=	-openobex
