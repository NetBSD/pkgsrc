# $NetBSD: buildlink3.mk,v 1.3 2025/12/25 22:45:28 adam Exp $

BUILDLINK_TREE+=	py-boost-cmake

.if !defined(PY_BOOST_CMAKE_BUILDLINK3_MK)
PY_BOOST_CMAKE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py-boost-cmake+=	py-boost-cmake-1.90.*
BUILDLINK_ABI_DEPENDS.py-boost-cmake+=	py-boost-cmake-1.90.*
BUILDLINK_PKGSRCDIR.py-boost-cmake?=	../../devel/py-boost-cmake
.endif # PY_BOOST_CMAKE_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-boost-cmake
