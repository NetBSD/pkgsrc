# $NetBSD: buildlink3.mk,v 1.19 2020/11/05 09:07:08 ryoon Exp $

BUILDLINK_TREE+=	dbus-sharp

.if !defined(DBUS_SHARP_BUILDLINK3_MK)
DBUS_SHARP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.dbus-sharp+=	dbus-sharp>=0.7.0
BUILDLINK_ABI_DEPENDS.dbus-sharp?=	dbus-sharp>=0.7.0nb20
BUILDLINK_PKGSRCDIR.dbus-sharp?=	../../sysutils/dbus-sharp

.include "../../lang/mono/buildlink3.mk"
.endif	# DBUS_SHARP_BUILDLINK3_MK

BUILDLINK_TREE+=	-dbus-sharp
