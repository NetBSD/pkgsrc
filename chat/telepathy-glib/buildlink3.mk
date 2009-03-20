# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:24:02 joerg Exp $

BUILDLINK_TREE+=	telepathy-glib

.if !defined(TELEPATHY_GLIB_BUILDLINK3_MK)
TELEPATHY_GLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.telepathy-glib+=	telepathy-glib>=0.7.18
BUILDLINK_PKGSRCDIR.telepathy-glib?=	../../chat/telepathy-glib

PRINT_PLIST_AWK+=	/^@dirrm include\/telepathy-1.0$$/ \
			{ print "@comment in telepathy-glib: " $$0; next; }

.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.endif # TELEPATHY_GLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-telepathy-glib
