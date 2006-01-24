# $NetBSD: buildlink3.mk,v 1.2 2006/01/24 07:32:36 wiz Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
XFCE4_FSGUARD_PLUGIN_BUILDLINK3_MK:=	${XFCE4_FSGUARD_PLUGIN_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	xfce4-fsguard-plugin
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxfce4-fsguard-plugin}
BUILDLINK_PACKAGES+=	xfce4-fsguard-plugin

.if !empty(XFCE4_FSGUARD_PLUGIN_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.xfce4-fsguard-plugin+=	xfce4-fsguard-plugin>=0.2.1
BUILDLINK_RECOMMENDED.xfce4-fsguard-plugin?=	xfce4-fsguard-plugin>=0.2.1nb1
BUILDLINK_PKGSRCDIR.xfce4-fsguard-plugin?=	../../sysutils/xfce4-fsguard-plugin
.endif	# XFCE4_FSGUARD_PLUGIN_BUILDLINK3_MK

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
