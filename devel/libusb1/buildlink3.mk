# $NetBSD: buildlink3.mk,v 1.5 2021/05/27 16:55:22 nia Exp $

BUILDLINK_TREE+=	libusb1

.if !defined(LIBUSB1_BUILDLINK3_MK)
LIBUSB1_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libusb1+=	libusb1>=1.0.9
BUILDLINK_PKGSRCDIR.libusb1?=	../../devel/libusb1

GCC_REQD+=	4.9 # -std=c11

.endif	# LIBUSB1_BUILDLINK3_MK

BUILDLINK_TREE+=	-libusb1
