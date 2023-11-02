# $NetBSD: buildlink3.mk,v 1.2 2023/11/02 06:37:24 pho Exp $

BUILDLINK_TREE+=	hs-fdo-notify

.if !defined(HS_FDO_NOTIFY_BUILDLINK3_MK)
HS_FDO_NOTIFY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-fdo-notify+=	hs-fdo-notify>=0.3.1
BUILDLINK_ABI_DEPENDS.hs-fdo-notify+=	hs-fdo-notify>=0.3.1nb1
BUILDLINK_PKGSRCDIR.hs-fdo-notify?=	../../sysutils/hs-fdo-notify

.include "../../sysutils/hs-dbus/buildlink3.mk"
.endif	# HS_FDO_NOTIFY_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-fdo-notify
