# $NetBSD: buildlink3.mk,v 1.30 2025/09/27 06:54:05 adam Exp $

BUILDLINK_TREE+=	py-boost

.if !defined(PY_BOOST_BUILDLINK3_MK)
PY_BOOST_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

# Use a dependency pattern that guarantees the proper ABI.
BUILDLINK_API_DEPENDS.py-boost+=	${PYPKGPREFIX}-boost-1.89.*
BUILDLINK_ABI_DEPENDS.py-boost+=	${PYPKGPREFIX}-boost-1.89.*
BUILDLINK_PKGSRCDIR.py-boost?=		../../devel/py-boost

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/py-boost-cmake/buildlink3.mk"
.endif # PY_BOOST_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-boost
