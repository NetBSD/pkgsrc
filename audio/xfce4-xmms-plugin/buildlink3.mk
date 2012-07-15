# $NetBSD: buildlink3.mk,v 1.29 2012/07/15 08:22:47 wiz Exp $

BUILDLINK_TREE+=	xfce4-xmms-plugin

.if !defined(XFCE4_XMMS_PLUGIN_BUILDLINK3_MK)
XFCE4_XMMS_PLUGIN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xfce4-xmms-plugin+=	xfce4-xmms-plugin>=0.5.1
BUILDLINK_ABI_DEPENDS.xfce4-xmms-plugin+=	xfce4-xmms-plugin>=0.5.1nb11
BUILDLINK_PKGSRCDIR.xfce4-xmms-plugin?=	../../audio/xfce4-xmms-plugin

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.endif # XFCE4_XMMS_PLUGIN_BUILDLINK3_MK

BUILDLINK_TREE+=	-xfce4-xmms-plugin
