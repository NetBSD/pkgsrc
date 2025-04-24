# $NetBSD: buildlink3.mk,v 1.15 2025/04/24 14:14:14 wiz Exp $

BUILDLINK_TREE+=	colord-gtk

.if !defined(COLORD_GTK_BUILDLINK3_MK)
COLORD_GTK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.colord-gtk+=	colord-gtk>=0.2.0
BUILDLINK_ABI_DEPENDS.colord-gtk?=	colord-gtk>=0.2.0nb14
BUILDLINK_PKGSRCDIR.colord-gtk?=	../../graphics/colord-gtk

.include "../../x11/gtk3/buildlink3.mk"
.endif	# COLORD_GTK_BUILDLINK3_MK

BUILDLINK_TREE+=	-colord-gtk
