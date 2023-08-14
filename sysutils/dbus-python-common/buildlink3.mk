# $NetBSD: buildlink3.mk,v 1.3 2023/08/14 05:25:14 wiz Exp $

BUILDLINK_TREE+=	dbus-python-common

.if !defined(DBUS_PYTHON_COMMON_BUILDLINK3_MK)
DBUS_PYTHON_COMMON_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.dbus-python-common?=	build

BUILDLINK_API_DEPENDS.dbus-python-common+=	dbus-python-common>=1.1.1
BUILDLINK_ABI_DEPENDS.dbus-python-common?=	dbus-python-common>=1.3.2nb1
BUILDLINK_PKGSRCDIR.dbus-python-common?=	../../sysutils/dbus-python-common

.include "../../sysutils/dbus/buildlink3.mk"
.endif	# DBUS_PYTHON_COMMON_BUILDLINK3_MK

BUILDLINK_TREE+=	-dbus-python-common
