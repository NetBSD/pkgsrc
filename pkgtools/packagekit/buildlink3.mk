# $NetBSD: buildlink3.mk,v 1.7 2012/04/27 12:32:01 obache Exp $

BUILDLINK_TREE+=	packagekit

.if !defined(PACKAGEKIT_BUILDLINK3_MK)
PACKAGEKIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.packagekit+=	packagekit>=0.4.0
BUILDLINK_ABI_DEPENDS.packagekit?=	packagekit>=0.4.0nb16
BUILDLINK_PKGSRCDIR.packagekit?=	../../pkgtools/packagekit

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.endif # PACKAGEKIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-packagekit
