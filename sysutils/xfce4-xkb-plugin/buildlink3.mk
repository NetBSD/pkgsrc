# $NetBSD: buildlink3.mk,v 1.12 2006/07/08 23:11:10 jlam Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
XFCE4_XKB_PLUGIN_BUILDLINK3_MK:=	${XFCE4_XKB_PLUGIN_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	xfce4-xkb-plugin
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxfce4-xkb-plugin}
BUILDLINK_PACKAGES+=	xfce4-xkb-plugin
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}xfce4-xkb-plugin

.if !empty(XFCE4_XKB_PLUGIN_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.xfce4-xkb-plugin+=	xfce4-xkb-plugin>=0.3.3
BUILDLINK_ABI_DEPENDS.xfce4-xkb-plugin?=	xfce4-xkb-plugin>=0.3.3nb1
BUILDLINK_PKGSRCDIR.xfce4-xkb-plugin?=	../../sysutils/xfce4-xkb-plugin
.endif	# XFCE4_XKB_PLUGIN_BUILDLINK3_MK

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH:S/+$//}
