# $NetBSD: buildlink3.mk,v 1.6 2012/07/31 15:46:20 wiz Exp $

BUILDLINK_TREE+=	dconf

.if !defined(DCONF_BUILDLINK3_MK)
DCONF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.dconf+=	dconf>=0.11.0
BUILDLINK_PKGSRCDIR.dconf?=	../../devel/dconf

.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.endif	# DCONF_BUILDLINK3_MK

BUILDLINK_TREE+=	-dconf
