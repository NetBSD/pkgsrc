# $NetBSD: buildlink3.mk,v 1.2 2004/03/05 19:25:40 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GNOME_VFS_BUILDLINK3_MK:=	${GNOME_VFS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gnome-vfs
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngnome-vfs}
BUILDLINK_PACKAGES+=	gnome-vfs

.if !empty(GNOME_VFS_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gnome-vfs+=	gnome-vfs>=1.0.5nb5
BUILDLINK_PKGSRCDIR.gnome-vfs?=	../../sysutils/gnome-vfs

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../databases/gnome-mime-data/buildlink3.mk"
.include "../../devel/GConf/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"

.endif	# GNOME_VFS_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
