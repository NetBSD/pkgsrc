# $NetBSD: buildlink3.mk,v 1.3 2020/05/24 23:03:17 joerg Exp $

BUILDLINK_TREE+=	libftdi

.if !defined(LIBFTDI_BUILDLINK3_MK)
LIBFTDI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libftdi+=	libftdi>=0.18<1
BUILDLINK_PKGSRCDIR.libftdi?=	../../devel/libftdi

.include "../../mk/libusb.buildlink3.mk"
.endif	# LIBFTDI_BUILDLINK3_MK

BUILDLINK_TREE+=	-libftdi
