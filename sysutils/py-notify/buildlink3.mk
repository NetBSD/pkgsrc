# $NetBSD: buildlink3.mk,v 1.12 2011/11/01 23:18:23 sbd Exp $

BUILDLINK_TREE+=	py-notify

.if !defined(PY_NOTIFY_BUILDLINK3_MK)
PY_NOTIFY_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.py-notify+=	${PYPKGPREFIX}-notify>=0.1.1
BUILDLINK_ABI_DEPENDS.py-notify?=	${PYPKGPREFIX}-notify>=0.1.1nb9
BUILDLINK_PKGSRCDIR.py-notify?=	../../sysutils/py-notify

.include "../../x11/py-gtk2/buildlink3.mk"
.endif # PY_NOTIFY_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-notify
