# $NetBSD: buildlink3.mk,v 1.2 2018/02/09 23:54:53 khorben Exp $

BUILDLINK_TREE+=	libusb-compat

.if !defined(LIBUSB_COMPAT_BUILDLINK3_MK)
LIBUSB_COMPAT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libusb-compat+=	libusb-compat>=0.1.6rc2
BUILDLINK_ABI_DEPENDS.libusb-compat+=	libusb-compat>=0.1.6rc2
BUILDLINK_PKGSRCDIR.libusb-compat?=	../../devel/libusb-compat

.include "../../devel/libusb1/buildlink3.mk"
.endif	# LIBUSB_COMPAT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libusb-compat
