# $NetBSD: buildlink3.mk,v 1.3 2004/10/03 00:18:17 tv Exp $

BUILDLINK_DEPTH:=				${BUILDLINK_DEPTH}+
XFCE4_SHOWDESKTOP_PLUGIN_BUILDLINK3_MK:=	${XFCE4_SHOWDESKTOP_PLUGIN_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	xfce4-showdesktop-plugin
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxfce4-showdesktop-plugin}
BUILDLINK_PACKAGES+=	xfce4-showdesktop-plugin

.if !empty(XFCE4_SHOWDESKTOP_PLUGIN_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.xfce4-showdesktop-plugin+=	xfce4-showdesktop-plugin>=0.1.1nb4
BUILDLINK_RECOMMENDED.xfce4-showdesktop-plugin+=	xfce4-showdesktop-plugin>=0.1.1nb5
BUILDLINK_PKGSRCDIR.xfce4-showdesktop-plugin?=	../../sysutils/xfce4-showdesktop-plugin
.endif	# XFCE4_SHOWDESKTOP_PLUGIN_BUILDLINK3_MK

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
