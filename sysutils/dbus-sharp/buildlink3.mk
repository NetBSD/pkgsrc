# $NetBSD: buildlink3.mk,v 1.11 2017/09/18 09:53:05 maya Exp $

BUILDLINK_TREE+=	dbus-sharp

.if !defined(DBUS_SHARP_BUILDLINK3_MK)
DBUS_SHARP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.dbus-sharp+=	dbus-sharp>=0.7.0
BUILDLINK_ABI_DEPENDS.dbus-sharp?=	dbus-sharp>=0.7.0nb12
BUILDLINK_PKGSRCDIR.dbus-sharp?=	../../sysutils/dbus-sharp

.include "../../lang/mono/buildlink3.mk"
.endif	# DBUS_SHARP_BUILDLINK3_MK

BUILDLINK_TREE+=	-dbus-sharp
