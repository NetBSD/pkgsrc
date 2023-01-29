# $NetBSD: buildlink3.mk,v 1.16 2023/01/29 21:14:24 ryoon Exp $

BUILDLINK_TREE+=	deforaos-phone

.if !defined(DEFORAOS_PHONE_BUILDLINK3_MK)
DEFORAOS_PHONE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.deforaos-phone+=	deforaos-phone>=0.6.0
BUILDLINK_ABI_DEPENDS.deforaos-phone?=	deforaos-phone>=0.6.0nb8
BUILDLINK_PKGSRCDIR.deforaos-phone?=	../../comms/deforaos-phone

.include "../../x11/deforaos-libdesktop/buildlink3.mk"
.endif	# DEFORAOS_PHONE_BUILDLINK3_MK

BUILDLINK_TREE+=	-deforaos-phone
