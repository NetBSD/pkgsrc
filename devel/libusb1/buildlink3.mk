# $NetBSD: buildlink3.mk,v 1.3 2020/05/25 06:47:40 plunky Exp $

BUILDLINK_TREE+=	libusb1

.if !defined(LIBUSB1_BUILDLINK3_MK)
LIBUSB1_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libusb1+=	libusb1>=1.0.9
BUILDLINK_PKGSRCDIR.libusb1?=	../../devel/libusb1
.endif	# LIBUSB1_BUILDLINK3_MK

BUILDLINK_TREE+=	-libusb1
