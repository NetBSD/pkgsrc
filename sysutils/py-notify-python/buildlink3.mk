# $NetBSD: buildlink3.mk,v 1.11 2017/02/12 06:24:50 ryoon Exp $

BUILDLINK_TREE+=	py-notify-python

.if !defined(PY_NOTIFY_PYTHON_BUILDLINK3_MK)
PY_NOTIFY_PYTHON_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.py-notify-python+=	${PYPKGPREFIX}-notify-python>=0.1.1
BUILDLINK_ABI_DEPENDS.py-notify-python+=	${PYPKGPREFIX}-notify-python>=0.1.1nb29
BUILDLINK_PKGSRCDIR.py-notify-python?=	../../sysutils/py-notify-python

.include "../../x11/py-gtk2/buildlink3.mk"
.endif # PY_NOTIFY_PYTHON_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-notify-python
