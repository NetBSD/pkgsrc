# $NetBSD: buildlink3.mk,v 1.27 2012/03/03 00:12:10 wiz Exp $

BUILDLINK_TREE+=	xfce4-xmms-plugin

.if !defined(XFCE4_XMMS_PLUGIN_BUILDLINK3_MK)
XFCE4_XMMS_PLUGIN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xfce4-xmms-plugin+=	xfce4-xmms-plugin>=0.5.1
BUILDLINK_ABI_DEPENDS.xfce4-xmms-plugin?=	xfce4-xmms-plugin>=0.5.1nb10
BUILDLINK_PKGSRCDIR.xfce4-xmms-plugin?=	../../audio/xfce4-xmms-plugin

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.endif # XFCE4_XMMS_PLUGIN_BUILDLINK3_MK

BUILDLINK_TREE+=	-xfce4-xmms-plugin
