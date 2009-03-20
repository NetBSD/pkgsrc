# $NetBSD: buildlink3.mk,v 1.10 2009/03/20 19:24:11 joerg Exp $

BUILDLINK_TREE+=	cmake

.if !defined(CMAKE_BUILDLINK3_MK)
CMAKE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cmake+=	cmake>=2.4.6nb3
BUILDLINK_PKGSRCDIR.cmake?=	../../devel/cmake
BUILDLINK_DEPMETHOD.cmake?=	build
BUILDLINK_FILES.cmake+=		share/cmake-*/include/*
.endif # CMAKE_BUILDLINK3_MK

BUILDLINK_TREE+=	-cmake
