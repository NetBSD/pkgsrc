# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:24:27 joerg Exp $

BUILDLINK_TREE+=	py-ctypes

.if !defined(PY_CTYPES_BUILDLINK3_MK)
PY_CTYPES_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.py-ctypes+=	${PYPKGPREFIX}-ctypes>=1.0.0
BUILDLINK_PKGSRCDIR.py-ctypes?=		../../devel/py-ctypes
.endif # PY_CTYPES_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-ctypes
