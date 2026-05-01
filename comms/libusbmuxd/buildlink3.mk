# $NetBSD: buildlink3.mk,v 1.1 2026/05/01 19:58:51 vins Exp $

BUILDLINK_TREE+=	libusbmuxd

.if !defined(LIBUSBMUXD_BUILDLINK3_MK)
LIBUSBMUXD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libusbmuxd+=	libusbmuxd>=2.1.1
BUILDLINK_PKGSRCDIR.libusbmuxd?=	../../comms/libusbmuxd

.include "../../textproc/libplist/buildlink3.mk"
.include "../../misc/libimobiledevice-glue/buildlink3.mk"
.endif	# LIBUSBMUXD_BUILDLINK3_MK

BUILDLINK_TREE+=	-libusbmuxd
