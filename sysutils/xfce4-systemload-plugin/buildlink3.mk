# $NetBSD: buildlink3.mk,v 1.13 2006/07/08 23:11:10 jlam Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
XFCE4_SYSTEMLOAD_PLUGIN_BUILDLINK3_MK:=	${XFCE4_SYSTEMLOAD_PLUGIN_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	xfce4-systemload-plugin
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxfce4-systemload-plugin}
BUILDLINK_PACKAGES+=	xfce4-systemload-plugin
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}xfce4-systemload-plugin

.if !empty(XFCE4_SYSTEMLOAD_PLUGIN_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.xfce4-systemload-plugin+=	xfce4-systemload-plugin>=0.3.6
BUILDLINK_ABI_DEPENDS.xfce4-systemload-plugin?=	xfce4-systemload-plugin>=0.3.6nb4
BUILDLINK_PKGSRCDIR.xfce4-systemload-plugin?=	../../sysutils/xfce4-systemload-plugin
.endif	# XFCE4_SYSTEMLOAD_PLUGIN_BUILDLINK3_MK

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH:S/+$//}
