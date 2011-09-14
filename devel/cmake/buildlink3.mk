# $NetBSD: buildlink3.mk,v 1.11 2011/09/14 17:54:48 brook Exp $

BUILDLINK_TREE+=	cmake

.if !defined(CMAKE_BUILDLINK3_MK)
CMAKE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cmake+=	cmake>=2.8.5nb1
BUILDLINK_PKGSRCDIR.cmake?=	../../devel/cmake
BUILDLINK_DEPMETHOD.cmake?=	build
BUILDLINK_FILES.cmake+=		share/cmake-*/include/*
.endif # CMAKE_BUILDLINK3_MK

BUILDLINK_TREE+=	-cmake
