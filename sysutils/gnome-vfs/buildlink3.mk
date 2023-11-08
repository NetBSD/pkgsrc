# $NetBSD: buildlink3.mk,v 1.75 2023/11/08 13:20:56 wiz Exp $

BUILDLINK_TREE+=	gnome-vfs

.if !defined(GNOME_VFS_BUILDLINK3_MK)
GNOME_VFS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnome-vfs+=	gnome-vfs>=2.8.0
BUILDLINK_ABI_DEPENDS.gnome-vfs+=	gnome-vfs>=2.24.4nb54
BUILDLINK_PKGSRCDIR.gnome-vfs?=		../../sysutils/gnome-vfs

pkgbase := gnome-vfs
.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.gnome-vfs:Mavahi}
.  include "../../net/avahi/buildlink3.mk"
.endif

.include "../../devel/GConf/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"

.endif # GNOME_VFS_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnome-vfs
