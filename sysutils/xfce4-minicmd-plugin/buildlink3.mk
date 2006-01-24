# $NetBSD: buildlink3.mk,v 1.7 2006/01/24 07:32:36 wiz Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
XFCE4_MINICMD_PLUGIN_BUILDLINK3_MK:=	${XFCE4_MINICMD_PLUGIN_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	xfce4-minicmd-plugin
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxfce4-minicmd-plugin}
BUILDLINK_PACKAGES+=	xfce4-minicmd-plugin

.if !empty(XFCE4_MINICMD_PLUGIN_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.xfce4-minicmd-plugin+=	xfce4-minicmd-plugin>=0.3.0
BUILDLINK_RECOMMENDED.xfce4-minicmd-plugin?=	xfce4-minicmd-plugin>=0.3.0nb1
BUILDLINK_PKGSRCDIR.xfce4-minicmd-plugin?=	../../sysutils/xfce4-minicmd-plugin
.endif	# XFCE4_MINICMD_PLUGIN_BUILDLINK3_MK

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
