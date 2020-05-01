# $NetBSD: buildlink3.mk,v 1.2 2020/05/01 07:54:38 adam Exp $

BUILDLINK_TREE+=	py-pybind11

.if !defined(PY_PYBIND11_BUILDLINK3_MK)
PY_PYBIND11_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"
BUILDLINK_API_DEPENDS.py-pybind11+=	${PYPKGPREFIX}-pybind11>=2.5.0
BUILDLINK_PKGSRCDIR.py-pybind11?=	../../devel/py-pybind11
BUILDLINK_DEPMETHOD.py-pybind11?=	build
.endif	# PY_PYBIND11_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-pybind11
