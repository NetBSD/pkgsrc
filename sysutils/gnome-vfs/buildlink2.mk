# $NetBSD: buildlink2.mk,v 1.8 2004/01/03 18:49:52 reed Exp $

.if !defined(GNOME_VFS_BUILDLINK2_MK)
GNOME_VFS_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		gnome-vfs
BUILDLINK_DEPENDS.gnome-vfs?=	gnome-vfs>=1.0.5nb5
BUILDLINK_PKGSRCDIR.gnome-vfs?=	../../sysutils/gnome-vfs

EVAL_PREFIX+=			BUILDLINK_PREFIX.gnome-vfs=gnome-vfs
BUILDLINK_PREFIX.gnome-vfs_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.gnome-vfs=	include/gnome-vfs-1.0/*/*
BUILDLINK_FILES.gnome-vfs+=	lib/gnome-vfs-1.0/include/*
BUILDLINK_FILES.gnome-vfs+=	lib/libgnomevfs-pthread.*
BUILDLINK_FILES.gnome-vfs+=	lib/libgnomevfs.*

.include "../../converters/libiconv/buildlink2.mk"
.include "../../devel/GConf/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"

BUILDLINK_TARGETS+=	gnome-vfs-buildlink

gnome-vfs-buildlink: _BUILDLINK_USE

.endif	# GNOME_VFS_BUILDLINK2_MK
