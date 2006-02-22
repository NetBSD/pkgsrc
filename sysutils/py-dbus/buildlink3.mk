# $NetBSD: buildlink3.mk,v 1.2 2006/02/22 21:01:00 wiz Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
PY_DBUS_BUILDLINK3_MK:=		${PY_DBUS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	py-dbus
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npy-dbus}
BUILDLINK_PACKAGES+=	py-dbus

.if !empty(PY_DBUS_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.py-dbus+=	${PYPKGPREFIX}-dbus>=0.23.4
BUILDLINK_RECOMMENDED.py-dbus?=	${PYPKGPREFIX}-dbus>=0.23.4nb2
BUILDLINK_PKGSRCDIR.py-dbus?=	../../sysutils/py-dbus
.endif	# PY_DBUS_BUILDLINK3_MK

.include "../../lang/python/pyversion.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
