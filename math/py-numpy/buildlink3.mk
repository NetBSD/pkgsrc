# $NetBSD: buildlink3.mk,v 1.5 2020/04/27 17:00:35 adam Exp $

BUILDLINK_TREE+=	py-numpy

.if !defined(PY_NUMPY_BUILDLINK3_MK)
PY_NUMPY_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.py-numpy+=	${PYPKGPREFIX}-numpy>=1.0
.if ${_PYTHON_VERSION} == 27
BUILDLINK_PKGSRCDIR.py-numpy?=		../../math/py-numpy16
.else
BUILDLINK_PKGSRCDIR.py-numpy?=		../../math/py-numpy
.endif

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} != "Darwin"
.include "../../math/blas/buildlink3.mk"
.include "../../math/lapack/buildlink3.mk"
.endif
.endif # PY_NUMPY_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-numpy
