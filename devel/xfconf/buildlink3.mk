# $NetBSD: buildlink3.mk,v 1.9 2012/09/15 10:04:22 obache Exp $

BUILDLINK_TREE+=	xfconf

.if !defined(XFCONF_BUILDLINK3_MK)
XFCONF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xfconf+=	xfconf>=4.6.0
BUILDLINK_ABI_DEPENDS.xfconf+=	xfconf>=4.6.1nb11
BUILDLINK_PKGSRCDIR.xfconf?=	../../devel/xfconf

.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.endif	# XFCONF_BUILDLINK3_MK

BUILDLINK_TREE+=	-xfconf
