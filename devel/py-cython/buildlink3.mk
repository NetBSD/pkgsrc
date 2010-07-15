# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/07/15 17:41:57 drochner Exp $

BUILDLINK_TREE+=	pycython

.if !defined(PY_CYTHON_BUILDLINK3_MK)
PY_CYTHON_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.pycython+= ${PYPKGPREFIX}-cython>=0.12.1
BUILDLINK_PKGSRCDIR.pycython?=	../../devel/py-cython

.endif # PY_CYTHON_BUILDLINK3_MK

BUILDLINK_TREE+=	-pycython
