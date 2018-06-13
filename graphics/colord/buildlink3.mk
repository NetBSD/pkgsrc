# $NetBSD: buildlink3.mk,v 1.1 2018/06/13 15:49:40 youri Exp $

BUILDLINK_TREE+=	colord

.if !defined(COLORD_BUILDLINK3_MK)
COLORD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.colord+=	colord>=1.2.12
BUILDLINK_PKGSRCDIR.colord?=	../../cinnamon/colord

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
#.include "../../print/cups-base/buildlink3.mk"
#.include "../../wip/geocode-glib/buildlink3.mk"
#.include "../../devel/nss/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
#.include "../../databases/sqlite3/buildlink3.mk"
#.include "../../security/polkit/buildlink3.mk"
#.include "../../devel/libdbusmenu-qt/buildlink3.mk"
#.include "../../sysutils/dbus/buildlink3.mk"
#.include "../../devel/gobject-introspection/buildlink3.mk"
.endif	# COLORD_BUILDLINK3_MK

BUILDLINK_TREE+=	-colord
