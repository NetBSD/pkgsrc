# $NetBSD: buildlink3.mk,v 1.28.2.1 2012/10/03 12:09:33 spz Exp $

BUILDLINK_TREE+=	xfce4-cpugraph-plugin

.if !defined(XFCE4_CPUGRAPH_PLUGIN_BUILDLINK3_MK)
XFCE4_CPUGRAPH_PLUGIN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xfce4-cpugraph-plugin+=	xfce4-cpugraph-plugin>=0.3.0
BUILDLINK_ABI_DEPENDS.xfce4-cpugraph-plugin+=	xfce4-cpugraph-plugin>=0.3.0nb13
BUILDLINK_PKGSRCDIR.xfce4-cpugraph-plugin?=	../../sysutils/xfce4-cpugraph-plugin

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.endif # XFCE4_CPUGRAPH_PLUGIN_BUILDLINK3_MK

BUILDLINK_TREE+=	-xfce4-cpugraph-plugin
