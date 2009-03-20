# $NetBSD: buildlink3.mk,v 1.13 2009/03/20 19:25:23 joerg Exp $

BUILDLINK_TREE+=	dbus

.if !defined(DBUS_BUILDLINK3_MK)
DBUS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.dbus+=	dbus>=0.91
BUILDLINK_PKGSRCDIR.dbus?=	../../sysutils/dbus

PRINT_PLIST_AWK+=	/^@dirrm include\/dbus-1.0\/dbus$$/ \
				{ print "@comment in dbus: " $$0; next; }
PRINT_PLIST_AWK+=	/^@exec ..MKDIR. %D\/share\/dbus-1\/services/ { next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/dbus-1\/services/ \
				{ print "@comment in dbus: " $$0; next }
PRINT_PLIST_AWK+=	/^@dirrm share\/dbus-1/ \
				{ print "@comment in dbus: " $$0; next }

.include "../../textproc/expat/buildlink3.mk"
.endif # DBUS_BUILDLINK3_MK

BUILDLINK_TREE+=	-dbus
