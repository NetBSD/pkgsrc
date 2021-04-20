# $NetBSD: buildlink3.mk,v 1.9 2021/04/20 20:53:48 thor Exp $

BUILDLINK_TREE+=	py-numpy

.if !defined(PY_NUMPY_BUILDLINK3_MK)
PY_NUMPY_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.py-numpy+=	${PYPKGPREFIX}-numpy>=1.0
.if ${_PYTHON_VERSION} == 27
BUILDLINK_ABI_DEPENDS.py-numpy?=	${PYPKGPREFIX}-numpy>=1.16.6nb1
BUILDLINK_PKGSRCDIR.py-numpy?=		../../math/py-numpy16
.else
BUILDLINK_ABI_DEPENDS.py-numpy?=	${PYPKGPREFIX}-numpy>=1.19.2nb1
BUILDLINK_PKGSRCDIR.py-numpy?=		../../math/py-numpy
.endif

.include "../../mk/bsd.fast.prefs.mk"

.include "../../math/py-numpy/Makefile.make_env"
.include "../../math/cblas/buildlink3.mk"

.endif # PY_NUMPY_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-numpy
