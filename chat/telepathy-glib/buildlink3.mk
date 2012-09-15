# $NetBSD: buildlink3.mk,v 1.8 2012/09/15 10:03:56 obache Exp $

BUILDLINK_TREE+=	telepathy-glib

.if !defined(TELEPATHY_GLIB_BUILDLINK3_MK)
TELEPATHY_GLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.telepathy-glib+=	telepathy-glib>=0.7.18
BUILDLINK_ABI_DEPENDS.telepathy-glib+=	telepathy-glib>=0.14.3nb7
BUILDLINK_PKGSRCDIR.telepathy-glib?=	../../chat/telepathy-glib

.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.endif # TELEPATHY_GLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-telepathy-glib
