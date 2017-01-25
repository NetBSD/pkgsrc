# $NetBSD: buildlink3.mk,v 1.3 2017/01/25 16:09:06 adam Exp $

BUILDLINK_TREE+=	py-cython

.if !defined(PY_CYTHON_BUILDLINK3_MK)
PY_CYTHON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py-cython+=	${PYPKGPREFIX}-cython>=0.12.1
BUILDLINK_PKGSRCDIR.py-cython?=		../../devel/py-cython
.endif	# PY_CYTHON_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-cython
