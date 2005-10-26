# $NetBSD: buildlink3.mk,v 1.1.1.1 2005/10/26 04:44:56 minskim Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
XFCE4_QUICKLAUNCH_PLUGIN_BUILDLINK3_MK:=${XFCE4_QUICKLAUNCH_PLUGIN_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	xfce4-quicklaunch-plugin
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxfce4-quicklaunch-plugin}
BUILDLINK_PACKAGES+=	xfce4-quicklaunch-plugin

.if !empty(XFCE4_QUICKLAUNCH_PLUGIN_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.xfce4-quicklaunch-plugin+=	xfce4-quicklaunch-plugin>=0.81
BUILDLINK_PKGSRCDIR.xfce4-quicklaunch-plugin?=	../../sysutils/xfce4-quicklaunch-plugin
.endif	# XFCE4_QUICKLAUNCH_PLUGIN_BUILDLINK3_MK

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
