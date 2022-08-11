# $NetBSD: buildlink3.mk,v 1.10 2022/08/11 05:09:14 gutteridge Exp $

BUILDLINK_TREE+=	baloo-widgets

.if !defined(BALOO_WIDGETS_BUILDLINK3_MK)
BALOO_WIDGETS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.baloo-widgets+=	baloo-widgets>=16.04.0
BUILDLINK_ABI_DEPENDS.baloo-widgets?=	baloo-widgets>=20.12.3nb8
BUILDLINK_PKGSRCDIR.baloo-widgets?=	../../sysutils/baloo-widgets

.include "../../sysutils/baloo5/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# BALOO_WIDGETS_BUILDLINK3_MK

BUILDLINK_TREE+=	-baloo-widgets
