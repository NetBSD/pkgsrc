# $NetBSD: buildlink3.mk,v 1.14 2006/10/12 06:06:07 martti Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
XFCE4_XMMS_PLUGIN_BUILDLINK3_MK:=	${XFCE4_XMMS_PLUGIN_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	xfce4-xmms-plugin
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxfce4-xmms-plugin}
BUILDLINK_PACKAGES+=	xfce4-xmms-plugin
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}xfce4-xmms-plugin

.if ${XFCE4_XMMS_PLUGIN_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.xfce4-xmms-plugin+=	xfce4-xmms-plugin>=0.3.1nb3
BUILDLINK_PKGSRCDIR.xfce4-xmms-plugin?=	../../audio/xfce4-xmms-plugin
.endif	# XFCE4_XMMS_PLUGIN_BUILDLINK3_MK

.include "../../audio/xmms/buildlink3.mk"
.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH:S/+$//}
