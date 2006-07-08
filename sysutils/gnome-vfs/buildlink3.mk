# $NetBSD: buildlink3.mk,v 1.15 2006/07/08 23:11:09 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GNOME_VFS_BUILDLINK3_MK:=	${GNOME_VFS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gnome-vfs
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngnome-vfs}
BUILDLINK_PACKAGES+=	gnome-vfs
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}gnome-vfs

.if !empty(GNOME_VFS_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.gnome-vfs+=		gnome-vfs>=1.0.5nb7
BUILDLINK_ABI_DEPENDS.gnome-vfs+=	gnome-vfs>=1.0.5nb11
BUILDLINK_PKGSRCDIR.gnome-vfs?=	../../sysutils/gnome-vfs
.endif	# GNOME_VFS_BUILDLINK3_MK

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../databases/gnome-mime-data/buildlink3.mk"
.include "../../devel/GConf/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
