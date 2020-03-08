# $NetBSD: buildlink3.mk,v 1.7 2020/03/08 16:48:10 wiz Exp $

BUILDLINK_TREE+=	eggdbus

.if !defined(EGGDBUS_BUILDLINK3_MK)
EGGDBUS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.eggdbus+=	eggdbus>=0.6
BUILDLINK_ABI_DEPENDS.eggdbus+=	eggdbus>=0.6nb5
BUILDLINK_PKGSRCDIR.eggdbus?=	../../sysutils/eggdbus

.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.endif	# EGGDBUS_BUILDLINK3_MK

BUILDLINK_TREE+=	-eggdbus
