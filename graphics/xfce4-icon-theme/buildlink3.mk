# $NetBSD: buildlink3.mk,v 1.29.2.1 2012/10/03 12:08:16 spz Exp $

BUILDLINK_TREE+=	xfce4-icon-theme

.if !defined(XFCE4_ICON_THEME_BUILDLINK3_MK)
XFCE4_ICON_THEME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xfce4-icon-theme+=	xfce4-icon-theme>=4.4.3
BUILDLINK_ABI_DEPENDS.xfce4-icon-theme+=	xfce4-icon-theme>=4.4.3nb10
BUILDLINK_PKGSRCDIR.xfce4-icon-theme?=	../../graphics/xfce4-icon-theme

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.endif # XFCE4_ICON_THEME_BUILDLINK3_MK

BUILDLINK_TREE+=	-xfce4-icon-theme
