# $NetBSD: buildlink3.mk,v 1.1.1.1 2012/03/13 15:30:07 pettai Exp $

BUILDLINK_TREE+=	ykpers

.if !defined(YKPERS_BUILDLINK3_MK)
YKPERS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ykpers+=	ykpers>=1.6.3
BUILDLINK_PKGSRCDIR.ykpers?=	../../security/ykpers

.include "../../security/libyubikey/buildlink3.mk"
.include "../../devel/libusb/buildlink3.mk"
.endif	# YKPERS_BUILDLINK3_MK

BUILDLINK_TREE+=	-ykpers
