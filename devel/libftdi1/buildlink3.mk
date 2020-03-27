# $NetBSD: buildlink3.mk,v 1.4 2020/03/27 17:46:53 nia Exp $

BUILDLINK_TREE+=	libftdi1

.if !defined(LIBFTDI1_BUILDLINK3_MK)
LIBFTDI1_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libftdi1+=	libftdi1>=1.0
BUILDLINK_PKGSRCDIR.libftdi1?=		../../devel/libftdi1

.include "../../devel/libusb1/buildlink3.mk"
.endif	# LIBFTDI1_BUILDLINK3_MK

BUILDLINK_TREE+=	-libftdi1
