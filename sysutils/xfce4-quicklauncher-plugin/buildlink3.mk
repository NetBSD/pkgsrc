# $NetBSD: buildlink3.mk,v 1.3 2006/01/24 07:32:36 wiz Exp $

BUILDLINK_DEPTH:=				${BUILDLINK_DEPTH}+
XFCE4_QUICKLAUNCHER_PLUGIN_BUILDLINK3_MK:=	${XFCE4_QUICKLAUNCHER_PLUGIN_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	xfce4-quicklauncher-plugin
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxfce4-quicklauncher-plugin}
BUILDLINK_PACKAGES+=	xfce4-quicklauncher-plugin

.if !empty(XFCE4_QUICKLAUNCHER_PLUGIN_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.xfce4-quicklauncher-plugin+=	xfce4-quicklauncher-plugin>=0.81
BUILDLINK_RECOMMENDED.xfce4-quicklauncher-plugin?=	xfce4-quicklauncher-plugin>=0.81nb2
BUILDLINK_PKGSRCDIR.xfce4-quicklauncher-plugin?=	../../sysutils/xfce4-quicklauncher-plugin
.endif	# XFCE4_QUICKLAUNCHER_PLUGIN_BUILDLINK3_MK

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
