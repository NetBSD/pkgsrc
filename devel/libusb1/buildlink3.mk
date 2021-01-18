# $NetBSD: buildlink3.mk,v 1.4 2021/01/18 09:22:19 nia Exp $

BUILDLINK_TREE+=	libusb1

.if !defined(LIBUSB1_BUILDLINK3_MK)
LIBUSB1_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libusb1+=	libusb1>=1.0.9
BUILDLINK_PKGSRCDIR.libusb1?=	../../devel/libusb1

GCC_REQD+=	4.7 # -std=c11

.endif	# LIBUSB1_BUILDLINK3_MK

BUILDLINK_TREE+=	-libusb1
