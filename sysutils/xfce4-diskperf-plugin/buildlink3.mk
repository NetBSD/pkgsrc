# $NetBSD: buildlink3.mk,v 1.2 2004/03/18 09:12:14 jlam Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
XFCE4_DISKPERF_PLUGIN_BUILDLINK3_MK:=	${XFCE4_DISKPERF_PLUGIN_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	xfce4-diskperf-plugin
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxfce4-diskperf-plugin}
BUILDLINK_PACKAGES+=	xfce4-diskperf-plugin

.if !empty(XFCE4_DISKPERF_PLUGIN_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.xfce4-diskperf-plugin+=	xfce4-diskperf-plugin>=1.4nb4
BUILDLINK_PKGSRCDIR.xfce4-diskperf-plugin?=	../../sysutils/xfce4-diskperf-plugin
.endif	# XFCE4_DISKPERF_PLUGIN_BUILDLINK3_MK

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
