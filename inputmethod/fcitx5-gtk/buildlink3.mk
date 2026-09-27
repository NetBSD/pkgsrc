# $NetBSD: buildlink3.mk,v 1.4 2026/09/27 11:37:09 tnn Exp $

BUILDLINK_TREE+=	fcitx5-gtk

.if !defined(FCITX5_GTK_BUILDLINK3_MK)
FCITX5_GTK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fcitx5-gtk+=	fcitx5-gtk>=5.1.0
BUILDLINK_ABI_DEPENDS.fcitx5-gtk?=	fcitx5-gtk>=5.1.6nb3
BUILDLINK_PKGSRCDIR.fcitx5-gtk?=	../../inputmethod/fcitx5-gtk

.include "../../devel/glib2/buildlink3.mk"
.endif	# FCITX5_GTK_BUILDLINK3_MK

BUILDLINK_TREE+=	-fcitx5-gtk
