# $NetBSD: buildlink3.mk,v 1.2 2018/02/10 13:53:47 khorben Exp $

BUILDLINK_TREE+=	libftdi

.if !defined(LIBFTDI_BUILDLINK3_MK)
LIBFTDI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libftdi+=	libftdi>=0.18
BUILDLINK_PKGSRCDIR.libftdi?=	../../devel/libftdi

.include "../../mk/libusb.buildlink3.mk"
.endif	# LIBFTDI_BUILDLINK3_MK

BUILDLINK_TREE+=	-libftdi
