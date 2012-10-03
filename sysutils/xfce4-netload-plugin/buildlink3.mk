# $NetBSD: buildlink3.mk,v 1.32.2.1 2012/10/03 12:09:34 spz Exp $

BUILDLINK_TREE+=	xfce4-netload-plugin

.if !defined(XFCE4_NETLOAD_PLUGIN_BUILDLINK3_MK)
XFCE4_NETLOAD_PLUGIN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xfce4-netload-plugin+=	xfce4-netload-plugin>=0.4.0
BUILDLINK_ABI_DEPENDS.xfce4-netload-plugin+=	xfce4-netload-plugin>=0.4.0nb13
BUILDLINK_PKGSRCDIR.xfce4-netload-plugin?=	../../sysutils/xfce4-netload-plugin

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.endif # XFCE4_NETLOAD_PLUGIN_BUILDLINK3_MK

BUILDLINK_TREE+=	-xfce4-netload-plugin
