# $NetBSD: buildlink3.mk,v 1.6 2004/10/03 00:18:15 tv Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GNOME_VFS_BUILDLINK3_MK:=	${GNOME_VFS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gnome-vfs
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngnome-vfs}
BUILDLINK_PACKAGES+=	gnome-vfs

.if !empty(GNOME_VFS_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gnome-vfs+=	gnome-vfs>=1.0.5nb5
BUILDLINK_RECOMMENDED.gnome-vfs+=	gnome-vfs>=1.0.5nb6
BUILDLINK_PKGSRCDIR.gnome-vfs?=	../../sysutils/gnome-vfs
.endif	# GNOME_VFS_BUILDLINK3_MK

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../databases/gnome-mime-data/buildlink3.mk"
.include "../../devel/GConf/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
