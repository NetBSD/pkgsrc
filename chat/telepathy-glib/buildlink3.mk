# $NetBSD: buildlink3.mk,v 1.9 2020/03/08 16:47:27 wiz Exp $

BUILDLINK_TREE+=	telepathy-glib

.if !defined(TELEPATHY_GLIB_BUILDLINK3_MK)
TELEPATHY_GLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.telepathy-glib+=	telepathy-glib>=0.7.18
BUILDLINK_ABI_DEPENDS.telepathy-glib+=	telepathy-glib>=0.24.1nb13
BUILDLINK_PKGSRCDIR.telepathy-glib?=	../../chat/telepathy-glib

.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.endif # TELEPATHY_GLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-telepathy-glib
