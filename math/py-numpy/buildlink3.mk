# $NetBSD: buildlink3.mk,v 1.20 2023/12/27 09:06:03 thor Exp $

BUILDLINK_TREE+=	py-numpy

.if !defined(PY_NUMPY_BUILDLINK3_MK)
PY_NUMPY_BUILDLINK3_MK:=

USE_CXX_FEATURES+=	c++17

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.py-numpy+=	${PYPKGPREFIX}-numpy>=1.0
.if ${PYTHON_VERSION} < 309
BUILDLINK_ABI_DEPENDS.py-numpy+=	${PYPKGPREFIX}-numpy>=1.16.6nb3
BUILDLINK_PKGSRCDIR.py-numpy?=		../../math/py-numpy16
.else
BUILDLINK_ABI_DEPENDS.py-numpy+=	${PYPKGPREFIX}-numpy>=1.20.3nb1
BUILDLINK_PKGSRCDIR.py-numpy?=		../../math/py-numpy
.endif

.include "../../mk/bsd.fast.prefs.mk"

.include "../../math/py-numpy/make_env.mk"

BLAS_C_INTERFACE=	yes
.include "../../mk/blas.buildlink3.mk"

.endif # PY_NUMPY_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-numpy
