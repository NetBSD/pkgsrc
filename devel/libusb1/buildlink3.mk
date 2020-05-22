# $NetBSD: buildlink3.mk,v 1.2 2020/05/22 08:31:39 plunky Exp $

BUILDLINK_TREE+=	libusb1

.if !defined(LIBUSB1_BUILDLINK3_MK)
LIBUSB1_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libusb1+=	libusb1>=1.0.9
BUILDLINK_PKGSRCDIR.libusb1?=	../../devel/libusb1

BUILDLINK_INCDIRS.libusb1+=	include/libusb-1.0
BUILDLINK_TRANSFORM+=		l:usb:usb-1.0
.endif	# LIBUSB1_BUILDLINK3_MK

BUILDLINK_TREE+=	-libusb1
