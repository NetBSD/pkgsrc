# $NetBSD: buildlink3.mk,v 1.15 2023/01/03 17:36:16 wiz Exp $

BUILDLINK_TREE+=	deforaos-phone

.if !defined(DEFORAOS_PHONE_BUILDLINK3_MK)
DEFORAOS_PHONE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.deforaos-phone+=	deforaos-phone>=0.6.0
BUILDLINK_ABI_DEPENDS.deforaos-phone?=	deforaos-phone>=0.6.0nb7
BUILDLINK_PKGSRCDIR.deforaos-phone?=	../../comms/deforaos-phone

.include "../../x11/deforaos-libdesktop/buildlink3.mk"
.endif	# DEFORAOS_PHONE_BUILDLINK3_MK

BUILDLINK_TREE+=	-deforaos-phone
