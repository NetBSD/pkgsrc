# $NetBSD: buildlink3.mk,v 1.16 2012/09/15 10:06:31 obache Exp $

BUILDLINK_TREE+=	py-dbus

.if !defined(PY_DBUS_BUILDLINK3_MK)
PY_DBUS_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.py-dbus+=	${PYPKGPREFIX}-dbus>=0.23.4
BUILDLINK_ABI_DEPENDS.py-dbus+=	${PYPKGPREFIX}-dbus>=1.1.1nb1
BUILDLINK_PKGSRCDIR.py-dbus?=	../../sysutils/py-dbus

.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/dbus-python-common/buildlink3.mk"
.endif # PY_DBUS_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-dbus
