# $NetBSD: buildlink3.mk,v 1.1 2010/10/23 15:34:34 jakllsch Exp $

BUILDLINK_TREE+=	libftdi

.if !defined(LIBFTDI_BUILDLINK3_MK)
LIBFTDI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libftdi+=	libftdi>=0.18
BUILDLINK_PKGSRCDIR.libftdi?=	../../devel/libftdi

.include "../../devel/libusb/buildlink3.mk"
.endif	# LIBFTDI_BUILDLINK3_MK

BUILDLINK_TREE+=	-libftdi
