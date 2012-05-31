# $NetBSD: buildlink3.mk,v 1.1 2012/05/31 11:57:28 wiz Exp $

BUILDLINK_TREE+=	libusb1

.if !defined(LIBUSB1_BUILDLINK3_MK)
LIBUSB1_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libusb1+=	libusb1>=1.0.9
BUILDLINK_PKGSRCDIR.libusb1?=	../../devel/libusb1
.endif	# LIBUSB1_BUILDLINK3_MK

BUILDLINK_TREE+=	-libusb1
