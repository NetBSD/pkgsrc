# $NetBSD: buildlink2.mk,v 1.16 2004/04/01 18:21:20 jmmv Exp $
#
# This Makefile fragment is included by packages that use gnome-vfs2.
#
# This file was created automatically using createbuildlink 2.8.
#

.if !defined(GNOME_VFS2_BUILDLINK2_MK)
GNOME_VFS2_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			gnome-vfs2
BUILDLINK_DEPENDS.gnome-vfs2?=		gnome-vfs2>=2.6.0
BUILDLINK_PKGSRCDIR.gnome-vfs2?=	../../sysutils/gnome-vfs2

EVAL_PREFIX+=				BUILDLINK_PREFIX.gnome-vfs2=gnome-vfs2
BUILDLINK_PREFIX.gnome-vfs2_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.gnome-vfs2+=	include/gnome-vfs-2.0/libgnomevfs/*
BUILDLINK_FILES.gnome-vfs2+=	include/gnome-vfs-module-2.0/libgnomevfs/*
BUILDLINK_FILES.gnome-vfs2+=	lib/gnome-vfs-2.0/include/*
BUILDLINK_FILES.gnome-vfs2+=	lib/libgnomevfs-2.*

.include "../../archivers/bzip2/buildlink2.mk"
.include "../../audio/cdparanoia/buildlink2.mk"
.include "../../databases/gnome-mime-data/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/GConf2/buildlink2.mk"
.include "../../devel/glib2/buildlink2.mk"
.include "../../devel/libbonobo/buildlink2.mk"
.include "../../devel/popt/buildlink2.mk"
.include "../../net/ORBit2/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../sysutils/fam/buildlink2.mk"

BUILDLINK_TARGETS+=	gnome-vfs2-buildlink

gnome-vfs2-buildlink: _BUILDLINK_USE

.endif	# GNOME_VFS2_BUILDLINK2_MK
