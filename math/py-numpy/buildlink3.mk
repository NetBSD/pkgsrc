# $NetBSD: buildlink3.mk,v 1.21 2024/08/15 22:00:56 wiz Exp $

BUILDLINK_TREE+=	py-numpy

.if !defined(PY_NUMPY_BUILDLINK3_MK)
PY_NUMPY_BUILDLINK3_MK:=

USE_CXX_FEATURES+=	c++17

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.py-numpy+=	${PYPKGPREFIX}-numpy>=1.0
BUILDLINK_ABI_DEPENDS.py-numpy+=	${PYPKGPREFIX}-numpy>=1.20.3nb1
BUILDLINK_PKGSRCDIR.py-numpy?=		../../math/py-numpy

.include "../../mk/bsd.fast.prefs.mk"

.include "../../math/py-numpy/make_env.mk"

BLAS_C_INTERFACE=	yes
.include "../../mk/blas.buildlink3.mk"

.endif # PY_NUMPY_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-numpy
