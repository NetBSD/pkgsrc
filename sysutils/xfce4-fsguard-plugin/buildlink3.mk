# $NetBSD: buildlink3.mk,v 1.7 2006/04/17 13:46:14 wiz Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
XFCE4_FSGUARD_PLUGIN_BUILDLINK3_MK:=	${XFCE4_FSGUARD_PLUGIN_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	xfce4-fsguard-plugin
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxfce4-fsguard-plugin}
BUILDLINK_PACKAGES+=	xfce4-fsguard-plugin

.if !empty(XFCE4_FSGUARD_PLUGIN_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.xfce4-fsguard-plugin+=	xfce4-fsguard-plugin>=0.2.1
BUILDLINK_ABI_DEPENDS.xfce4-fsguard-plugin?=	xfce4-fsguard-plugin>=0.2.1nb3
BUILDLINK_PKGSRCDIR.xfce4-fsguard-plugin?=	../../sysutils/xfce4-fsguard-plugin
.endif	# XFCE4_FSGUARD_PLUGIN_BUILDLINK3_MK

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH:S/+$//}
