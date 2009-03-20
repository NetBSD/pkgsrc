# $NetBSD: buildlink3.mk,v 1.20 2009/03/20 19:25:24 joerg Exp $

BUILDLINK_TREE+=	gnome-vfs

.if !defined(GNOME_VFS_BUILDLINK3_MK)
GNOME_VFS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnome-vfs+=	gnome-vfs>=2.8.0
BUILDLINK_ABI_DEPENDS.gnome-vfs+=	gnome-vfs>=2.20.1nb1
BUILDLINK_PKGSRCDIR.gnome-vfs?=		../../sysutils/gnome-vfs

PRINT_PLIST_AWK+=	/^@dirrm lib\/gnome-vfs-2.0\/modules/ \
				{ print "@comment in gnome-vfs: " $$0; next; }

.include "../../devel/GConf/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../mk/fam.buildlink3.mk"
.endif # GNOME_VFS_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnome-vfs
