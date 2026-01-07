# $NetBSD: buildlink3.mk,v 1.31 2026/01/07 08:48:48 wiz Exp $

BUILDLINK_TREE+=	baloo-widgets

.if !defined(BALOO_WIDGETS_BUILDLINK3_MK)
BALOO_WIDGETS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.baloo-widgets+=	baloo-widgets>=25.08.2
BUILDLINK_ABI_DEPENDS.baloo-widgets?=	baloo-widgets>=25.08.3nb1
BUILDLINK_PKGSRCDIR.baloo-widgets?=	../../sysutils/baloo-widgets

.include "../../sysutils/kf6-baloo/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# BALOO_WIDGETS_BUILDLINK3_MK

BUILDLINK_TREE+=	-baloo-widgets
