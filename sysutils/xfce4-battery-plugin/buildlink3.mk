# $NetBSD: buildlink3.mk,v 1.1 2007/04/27 11:09:26 martti Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
XFCE4_BATTERY_PLUGIN_BUILDLINK3_MK:=	${XFCE4_BATTERY_PLUGIN_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	xfce4-battery-plugin
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxfce4-battery-plugin}
BUILDLINK_PACKAGES+=	xfce4-battery-plugin
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}xfce4-battery-plugin

.if ${XFCE4_BATTERY_PLUGIN_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.xfce4-battery-plugin+=	xfce4-battery-plugin>=0.5.0
BUILDLINK_PKGSRCDIR.xfce4-battery-plugin?=	../../sysutils/xfce4-battery-plugin
.endif	# XFCE4_BATTERY_PLUGIN_BUILDLINK3_MK

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../devel/xfce4-dev-tools/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH:S/+$//}
