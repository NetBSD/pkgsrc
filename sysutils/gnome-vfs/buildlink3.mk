# $NetBSD: buildlink3.mk,v 1.1 2004/02/26 17:29:24 jmmv Exp $
#
# This Makefile fragment is included by packages that use gnome-vfs.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GNOME_VFS_BUILDLINK3_MK:=	${GNOME_VFS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gnome-vfs
.endif

.if !empty(GNOME_VFS_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			gnome-vfs
BUILDLINK_DEPENDS.gnome-vfs+=		gnome-vfs>=1.0.5nb5
BUILDLINK_PKGSRCDIR.gnome-vfs?=		../../sysutils/gnome-vfs

.include "../../converters/libiconv/buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../databases/gnome-mime-data/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/GConf/buildlink3.mk"

.endif # GNOME_VFS_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
