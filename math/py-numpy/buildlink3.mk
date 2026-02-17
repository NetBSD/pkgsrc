# $NetBSD: buildlink3.mk,v 1.22 2026/02/17 12:06:50 wiz Exp $

BUILDLINK_TREE+=	py-numpy

.if !defined(PY_NUMPY_BUILDLINK3_MK)
PY_NUMPY_BUILDLINK3_MK:=

USE_CXX_FEATURES+=	c++17

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.py-numpy+=	${PYPKGPREFIX}-numpy>=1.0
BUILDLINK_ABI_DEPENDS.py-numpy+=	${PYPKGPREFIX}-numpy>=1.20.3nb1
BUILDLINK_PKGSRCDIR.py-numpy?=		../../math/py-numpy

BUILDLINK_TARGETS+=	buildlink-numpy-unversioned
.PHONY: buildlink-numpy-unversioned
buildlink-numpy-unversioned:
	${LN} -s ${PREFIX}/${PYSITELIB}/numpy/_core/lib/pkgconfig/numpy.pc \
		${BUILDLINK_DIR}/lib/pkgconfig/numpy.pc

.include "../../mk/bsd.fast.prefs.mk"

.include "../../math/py-numpy/make_env.mk"

BLAS_C_INTERFACE=	yes
.include "../../mk/blas.buildlink3.mk"

.endif # PY_NUMPY_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-numpy
