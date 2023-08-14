# $NetBSD: buildlink3.mk,v 1.5 2023/08/14 05:24:11 wiz Exp $

BUILDLINK_TREE+=	libftdi1

.if !defined(LIBFTDI1_BUILDLINK3_MK)
LIBFTDI1_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libftdi1+=	libftdi1>=1.0
BUILDLINK_ABI_DEPENDS.libftdi1?=		libftdi1>=1.5nb7
BUILDLINK_PKGSRCDIR.libftdi1?=		../../devel/libftdi1

.include "../../devel/libusb1/buildlink3.mk"
.endif	# LIBFTDI1_BUILDLINK3_MK

BUILDLINK_TREE+=	-libftdi1
