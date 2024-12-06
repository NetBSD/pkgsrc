# $NetBSD: buildlink3.mk,v 1.1 2024/12/06 18:45:23 wiz Exp $

BUILDLINK_TREE+=	breeze-icons

.if !defined(BREEZE_ICONS_BUILDLINK3_MK)
BREEZE_ICONS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.breeze-icons+=	breeze-icons>=6.8.0
BUILDLINK_PKGSRCDIR.breeze-icons?=	../../graphics/breeze-icons

#.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# BREEZE_ICONS_BUILDLINK3_MK

BUILDLINK_TREE+=	-breeze-icons
