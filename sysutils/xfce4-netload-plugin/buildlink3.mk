# $NetBSD: buildlink3.mk,v 1.3 2004/10/03 00:18:17 tv Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
XFCE4_NETLOAD_PLUGIN_BUILDLINK3_MK:=	${XFCE4_NETLOAD_PLUGIN_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	xfce4-netload-plugin
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxfce4-netload-plugin}
BUILDLINK_PACKAGES+=	xfce4-netload-plugin

.if !empty(XFCE4_NETLOAD_PLUGIN_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.xfce4-netload-plugin+=	xfce4-netload-plugin>=0.2.2nb4
BUILDLINK_RECOMMENDED.xfce4-netload-plugin+=	xfce4-netload-plugin>=0.2.2nb5
BUILDLINK_PKGSRCDIR.xfce4-netload-plugin?=	../../sysutils/xfce4-netload-plugin
.endif	# XFCE4_NETLOAD_PLUGIN_BUILDLINK3_MK

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
