# $NetBSD: buildlink3.mk,v 1.2 2021/12/08 16:01:42 adam Exp $

BUILDLINK_TREE+=	gnome-autoar

.if !defined(GNOME_AUTOAR_BUILDLINK3_MK)
GNOME_AUTOAR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnome-autoar+=	gnome-autoar>=0.2.4
BUILDLINK_ABI_DEPENDS.gnome-autoar?=	gnome-autoar>=0.4.1nb1
BUILDLINK_PKGSRCDIR.gnome-autoar?=	../../archivers/gnome-autoar

.include "../../archivers/libarchive/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.endif	# GNOME_AUTOAR_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnome-autoar
