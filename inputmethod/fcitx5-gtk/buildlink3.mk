# $NetBSD: buildlink3.mk,v 1.2 2025/10/23 20:37:55 wiz Exp $

BUILDLINK_TREE+=	fcitx5-gtk

.if !defined(FCITX5_GTK_BUILDLINK3_MK)
FCITX5_GTK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fcitx5-gtk+=	fcitx5-gtk>=5.1.0
BUILDLINK_ABI_DEPENDS.fcitx5-gtk?=	fcitx5-gtk>=5.1.1nb11
BUILDLINK_PKGSRCDIR.fcitx5-gtk?=	../../inputmethod/fcitx5-gtk

.include "../../devel/glib2/buildlink3.mk"
.endif	# FCITX5_GTK_BUILDLINK3_MK

BUILDLINK_TREE+=	-fcitx5-gtk
