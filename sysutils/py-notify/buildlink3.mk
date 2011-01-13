# $NetBSD: buildlink3.mk,v 1.9 2011/01/13 13:36:45 wiz Exp $

BUILDLINK_TREE+=	py-notify

.if !defined(PY_NOTIFY_BUILDLINK3_MK)
PY_NOTIFY_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.py-notify+=	${PYPKGPREFIX}-notify>=0.1.1
BUILDLINK_ABI_DEPENDS.py-notify?=	${PYPKGPREFIX}-notify>=0.1.1nb7
BUILDLINK_PKGSRCDIR.py-notify?=	../../sysutils/py-notify

.include "../../x11/py-gtk2/buildlink3.mk"
.endif # PY_NOTIFY_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-notify
