# $NetBSD: buildlink3.mk,v 1.2 2012/11/19 11:40:27 pettai Exp $

BUILDLINK_TREE+=	ykpers

.if !defined(YKPERS_BUILDLINK3_MK)
YKPERS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ykpers+=	ykpers>=1.6.3
BUILDLINK_PKGSRCDIR.ykpers?=	../../security/ykpers

.include "../../security/libyubikey/buildlink3.mk"
.include "../../devel/libusb1/buildlink3.mk"
.endif	# YKPERS_BUILDLINK3_MK

BUILDLINK_TREE+=	-ykpers
