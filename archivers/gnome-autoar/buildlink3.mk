# $NetBSD: buildlink3.mk,v 1.1 2020/11/04 12:27:58 nia Exp $

BUILDLINK_TREE+=	gnome-autoar

.if !defined(GNOME_AUTOAR_BUILDLINK3_MK)
GNOME_AUTOAR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnome-autoar+=	gnome-autoar>=0.2.4
BUILDLINK_PKGSRCDIR.gnome-autoar?=	../../archivers/gnome-autoar

.include "../../archivers/libarchive/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.endif	# GNOME_AUTOAR_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnome-autoar
