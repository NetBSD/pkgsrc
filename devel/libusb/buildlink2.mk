# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/06/23 23:04:15 jlam Exp $

.if !defined(LIBUSB_BUILDLINK2_MK)
LIBUSB_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		libusb
BUILDLINK_DEPENDS.libusb?=	libusb>=0.1.5
BUILDLINK_PKGSRCDIR.libusb?=	../../devel/libusb

EVAL_PREFIX+=			BUILDLINK_PREFIX.libusb=libusb
BUILDLINK_FILES.libusb=		include/usb.h
BUILDLINK_FILES.libusb+=	lib/libusb-*.*
BUILDLINK_FILES.libusb+=	lib/libusb.*

BUILDLINK_TARGETS+=	libusb-buildlink

libusb-buildlink: _BUILDLINK_USE

.endif	# LIBUSB_BUILDLINK2_MK
