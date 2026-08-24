# $NetBSD: buildlink3.mk,v 1.5 2026/08/24 07:41:50 adam Exp $

BUILDLINK_TREE+=	py-boost-cmake

.if !defined(PY_BOOST_CMAKE_BUILDLINK3_MK)
PY_BOOST_CMAKE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py-boost-cmake+=	py-boost-cmake-1.92.*
BUILDLINK_ABI_DEPENDS.py-boost-cmake+=	py-boost-cmake-1.92.*
BUILDLINK_PKGSRCDIR.py-boost-cmake?=	../../devel/py-boost-cmake
.endif # PY_BOOST_CMAKE_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-boost-cmake
