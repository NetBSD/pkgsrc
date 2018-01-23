# $NetBSD: buildlink3.mk,v 1.1 2018/01/23 14:31:45 khorben Exp $

BUILDLINK_TREE+=	libusb-compat

.if !defined(LIBUSB_COMPAT_BUILDLINK3_MK)
LIBUSB_COMPAT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libusb-compat+=	libusb-compat>=0.1.6rc2
BUILDLINK_PKGSRCDIR.libusb-compat?=	../../devel/libusb-compat

.endif	# LIBUSB_COMPAT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libusb-compat
