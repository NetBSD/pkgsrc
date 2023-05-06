# $NetBSD: buildlink3.mk,v 1.15 2023/05/06 19:08:53 ryoon Exp $

BUILDLINK_TREE+=	baloo-widgets

.if !defined(BALOO_WIDGETS_BUILDLINK3_MK)
BALOO_WIDGETS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.baloo-widgets+=	baloo-widgets>=16.04.0
BUILDLINK_ABI_DEPENDS.baloo-widgets?=	baloo-widgets>=22.08.1nb5
BUILDLINK_PKGSRCDIR.baloo-widgets?=	../../sysutils/baloo-widgets

.include "../../sysutils/baloo5/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# BALOO_WIDGETS_BUILDLINK3_MK

BUILDLINK_TREE+=	-baloo-widgets
