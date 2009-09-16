# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/09/16 01:06:30 reed Exp $

BUILDLINK_TREE+=	xfconf

.if !defined(XFCONF_BUILDLINK3_MK)
XFCONF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xfconf+=	xfconf>=4.6.0
BUILDLINK_PKGSRCDIR.xfconf?=	../../devel/xfconf

.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libxfce4util/buildlink3.mk"
.endif	# XFCONF_BUILDLINK3_MK

BUILDLINK_TREE+=	-xfconf
