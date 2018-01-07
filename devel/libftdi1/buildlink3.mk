# $NetBSD: buildlink3.mk,v 1.2 2018/01/07 13:04:05 rillig Exp $

BUILDLINK_TREE+=	libftdi1

.if !defined(LIBFTDI1_BUILDLINK3_MK)
LIBFTDI1_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libftdi1+=	libftdi1>=1.0
BUILDLINK_PKGSRCDIR.libftdi1?=		../../devel/libftdi1

.include "../../devel/libusb/buildlink3.mk"
.endif	# LIBFTDI1_BUILDLINK3_MK

BUILDLINK_TREE+=	-libftdi1
