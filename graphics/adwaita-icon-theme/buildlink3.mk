# $NetBSD: buildlink3.mk,v 1.1 2014/11/05 23:29:48 prlw1 Exp $

BUILDLINK_TREE+=	adwaita-icon-theme

.if !defined(ADWAITA_ICON_THEME_BUILDLINK3_MK)
ADWAITA_ICON_THEME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.adwaita-icon-theme+=	adwaita-icon-theme>=3.14.1
BUILDLINK_PKGSRCDIR.adwaita-icon-theme?=	../../graphics/adwaita-icon-theme
.endif	# ADWAITA_ICON_THEME_BUILDLINK3_MK

BUILDLINK_TREE+=	-adwaita-icon-theme
