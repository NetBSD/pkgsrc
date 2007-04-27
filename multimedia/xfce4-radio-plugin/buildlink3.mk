# $NetBSD: buildlink3.mk,v 1.1.1.1 2007/04/27 10:48:06 martti Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
XFCE4_RADIO_PLUGIN_BUILDLINK3_MK:=	${XFCE4_RADIO_PLUGIN_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	xfce4-radio-plugin
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxfce4-radio-plugin}
BUILDLINK_PACKAGES+=	xfce4-radio-plugin
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}xfce4-radio-plugin

.if ${XFCE4_RADIO_PLUGIN_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.xfce4-radio-plugin+=	xfce4-radio-plugin>=0.2.0
BUILDLINK_PKGSRCDIR.xfce4-radio-plugin?=	../../multimedia/xfce4-radio-plugin
.endif	# XFCE4_RADIO_PLUGIN_BUILDLINK3_MK

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../devel/xfce4-dev-tools/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH:S/+$//}
