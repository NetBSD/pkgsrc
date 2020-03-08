# $NetBSD: buildlink3.mk,v 1.39 2020/03/08 16:48:12 wiz Exp $

BUILDLINK_TREE+=	p5-Gnome2-VFS

.if !defined(P5_GNOME2_VFS_BUILDLINK3_MK)
P5_GNOME2_VFS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.p5-Gnome2-VFS+=	p5-Gnome2-VFS>=1.081
BUILDLINK_ABI_DEPENDS.p5-Gnome2-VFS+=	p5-Gnome2-VFS>=1.083nb11
BUILDLINK_PKGSRCDIR.p5-Gnome2-VFS?=	../../sysutils/p5-Gnome2-VFS

.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../devel/p5-glib2/buildlink3.mk"
.endif # P5_GNOME2_VFS_BUILDLINK3_MK

BUILDLINK_TREE+=	-p5-Gnome2-VFS
