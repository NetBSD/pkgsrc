# $NetBSD: buildlink3.mk,v 1.1 2020/11/10 13:36:51 nia Exp $

BUILDLINK_TREE+=	colord-gtk

.if !defined(COLORD_GTK_BUILDLINK3_MK)
COLORD_GTK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.colord-gtk+=	colord-gtk>=0.2.0
BUILDLINK_PKGSRCDIR.colord-gtk?=	../../graphics/colord-gtk

.include "../../x11/gtk3/buildlink3.mk"
.endif	# COLORD_GTK_BUILDLINK3_MK

BUILDLINK_TREE+=	-colord-gtk
