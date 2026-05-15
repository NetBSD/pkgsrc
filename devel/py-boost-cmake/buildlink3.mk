# $NetBSD: buildlink3.mk,v 1.4 2026/05/15 09:13:49 adam Exp $

BUILDLINK_TREE+=	py-boost-cmake

.if !defined(PY_BOOST_CMAKE_BUILDLINK3_MK)
PY_BOOST_CMAKE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py-boost-cmake+=	py-boost-cmake-1.91.*
BUILDLINK_ABI_DEPENDS.py-boost-cmake+=	py-boost-cmake-1.91.*
BUILDLINK_PKGSRCDIR.py-boost-cmake?=	../../devel/py-boost-cmake
.endif # PY_BOOST_CMAKE_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-boost-cmake
