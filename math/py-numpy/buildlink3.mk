# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:24:58 joerg Exp $

BUILDLINK_TREE+=	pynumpy

.if !defined(PY_NUMPY_BUILDLINK3_MK)
PY_NUMPY_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.pynumpy+=	${PYPKGPREFIX}-numpy>=1.0
BUILDLINK_PKGSRCDIR.pynumpy?=	../../math/py-numpy

.include "../../math/blas/buildlink3.mk"
.include "../../math/lapack/buildlink3.mk"
.endif # PY_NUMPY_BUILDLINK3_MK

BUILDLINK_TREE+=	-pynumpy
