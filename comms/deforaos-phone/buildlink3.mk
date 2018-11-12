# $NetBSD: buildlink3.mk,v 1.7 2018/11/12 03:51:08 ryoon Exp $

BUILDLINK_TREE+=	deforaos-phone

.if !defined(DEFORAOS_PHONE_BUILDLINK3_MK)
DEFORAOS_PHONE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.deforaos-phone+=	deforaos-phone>=0.4.3
BUILDLINK_ABI_DEPENDS.deforaos-phone?=	deforaos-phone>=0.5.1nb3
BUILDLINK_PKGSRCDIR.deforaos-phone?=	../../comms/deforaos-phone

.include "../../x11/deforaos-libdesktop/buildlink3.mk"
.endif	# DEFORAOS_PHONE_BUILDLINK3_MK

BUILDLINK_TREE+=	-deforaos-phone
