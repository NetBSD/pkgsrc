# $NetBSD: buildlink3.mk,v 1.14 2007/12/05 07:48:46 martti Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
XFCE4_WEATHER_PLUGIN_BUILDLINK3_MK:=	${XFCE4_WEATHER_PLUGIN_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	xfce4-weather-plugin
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxfce4-weather-plugin}
BUILDLINK_PACKAGES+=	xfce4-weather-plugin
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}xfce4-weather-plugin

.if ${XFCE4_WEATHER_PLUGIN_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.xfce4-weather-plugin+=	xfce4-weather-plugin>=0.6.2
BUILDLINK_PKGSRCDIR.xfce4-weather-plugin?=	../../misc/xfce4-weather-plugin
.endif	# XFCE4_WEATHER_PLUGIN_BUILDLINK3_MK

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH:S/+$//}
