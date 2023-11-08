# $NetBSD: buildlink3.mk,v 1.36 2023/11/08 13:18:20 wiz Exp $

BUILDLINK_TREE+=	libopensync

.if !defined(LIBOPENSYNC_BUILDLINK3_MK)
LIBOPENSYNC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libopensync+=	libopensync>=0.22
BUILDLINK_ABI_DEPENDS.libopensync+=	libopensync>=0.22nb35
BUILDLINK_PKGSRCDIR.libopensync?=	../../comms/libopensync

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.endif # LIBOPENSYNC_BUILDLINK3_MK

BUILDLINK_TREE+=	-libopensync
