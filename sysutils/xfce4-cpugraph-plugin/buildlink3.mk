# $NetBSD: buildlink3.mk,v 1.12 2006/10/12 09:24:19 martti Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
XFCE4_CPUGRAPH_PLUGIN_BUILDLINK3_MK:=	${XFCE4_CPUGRAPH_PLUGIN_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	xfce4-cpugraph-plugin
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxfce4-cpugraph-plugin}
BUILDLINK_PACKAGES+=	xfce4-cpugraph-plugin
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}xfce4-cpugraph-plugin

.if ${XFCE4_CPUGRAPH_PLUGIN_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.xfce4-cpugraph-plugin+=	xfce4-cpugraph-plugin>=0.2.2nb4
BUILDLINK_PKGSRCDIR.xfce4-cpugraph-plugin?=	../../sysutils/xfce4-cpugraph-plugin
.endif	# XFCE4_CPUGRAPH_PLUGIN_BUILDLINK3_MK

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH:S/+$//}
