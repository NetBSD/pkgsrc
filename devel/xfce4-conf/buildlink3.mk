# $NetBSD: buildlink3.mk,v 1.15 2026/09/02 19:01:46 wiz Exp $

BUILDLINK_TREE+=	xfce4-conf

.if !defined(XFCE4_CONF_BUILDLINK3_MK)
XFCE4_CONF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xfce4-conf+=	xfce4-conf>=4.20.0
BUILDLINK_ABI_DEPENDS.xfce4-conf?=	xfce4-conf>=4.20.0nb7
BUILDLINK_PKGSRCDIR.xfce4-conf?=	../../devel/xfce4-conf

.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../x11/libxfce4util/buildlink3.mk"
.endif	# XFCE4_CONF_BUILDLINK3_MK

BUILDLINK_TREE+=	-xfce4-conf
