# $NetBSD: buildlink3.mk,v 1.1 2023/08/06 07:40:00 adam Exp $

BUILDLINK_TREE+=	py27-dbus

.if !defined(PY27_DBUS_BUILDLINK3_MK)
PY27_DBUS_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.py27-dbus+=	${PYPKGPREFIX}-dbus>=0.23.4
BUILDLINK_ABI_DEPENDS.py27-dbus+=	${PYPKGPREFIX}-dbus>=1.2.18
BUILDLINK_PKGSRCDIR.py27-dbus?=		../../sysutils/py27-dbus

.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.endif # PY27_DBUS_BUILDLINK3_MK

BUILDLINK_TREE+=	-py27-dbus
