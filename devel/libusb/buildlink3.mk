# $NetBSD: buildlink3.mk,v 1.8 2009/03/20 19:24:23 joerg Exp $

BUILDLINK_TREE+=	libusb

.if !defined(LIBUSB_BUILDLINK3_MK)
LIBUSB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libusb+=	libusb>=0.1.7
BUILDLINK_ABI_DEPENDS.libusb+=	libusb>=0.1.8nb2
BUILDLINK_PKGSRCDIR.libusb?=	../../devel/libusb
.endif # LIBUSB_BUILDLINK3_MK

BUILDLINK_TREE+=	-libusb
