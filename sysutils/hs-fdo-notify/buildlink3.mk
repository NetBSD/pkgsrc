# $NetBSD: buildlink3.mk,v 1.5 2025/03/05 03:39:52 pho Exp $

BUILDLINK_TREE+=	hs-fdo-notify

.if !defined(HS_FDO_NOTIFY_BUILDLINK3_MK)
HS_FDO_NOTIFY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-fdo-notify+=	hs-fdo-notify>=0.3.1
BUILDLINK_ABI_DEPENDS.hs-fdo-notify+=	hs-fdo-notify>=0.3.1nb4
BUILDLINK_PKGSRCDIR.hs-fdo-notify?=	../../sysutils/hs-fdo-notify

.include "../../sysutils/hs-dbus/buildlink3.mk"
.endif	# HS_FDO_NOTIFY_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-fdo-notify
