# $NetBSD: buildlink2.mk,v 1.3 2002/09/22 09:43:17 jlam Exp $

.if !defined(GNOME_VFS_BUILDLINK2_MK)
GNOME_VFS_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		gnome-vfs
BUILDLINK_DEPENDS.gnome-vfs?=	gnome-vfs>=1.0.2nb1
BUILDLINK_PKGSRCDIR.gnome-vfs?=	../../sysutils/gnome-vfs

EVAL_PREFIX+=			BUILDLINK_PREFIX.gnome-vfs=gnome-vfs
BUILDLINK_PREFIX.gnome-vfs_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.gnome-vfs=	include/gnome-vfs-1.0/*/*
BUILDLINK_FILES.gnome-vfs+=	lib/gnome-vfs-1.0/include/*
BUILDLINK_FILES.gnome-vfs+=	lib/libgnomevfs-pthread.*
BUILDLINK_FILES.gnome-vfs+=	lib/libgnomevfs.*

.include "../../devel/GConf/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"

BUILDLINK_TARGETS+=	gnome-vfs-buildlink

gnome-vfs-buildlink: _BUILDLINK_USE

.endif	# GNOME_VFS_BUILDLINK2_MK
