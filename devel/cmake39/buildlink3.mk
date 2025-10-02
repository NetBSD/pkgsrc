# $NetBSD: buildlink3.mk,v 1.1 2025/10/02 11:49:44 nia Exp $

BUILDLINK_TREE+=	cmake39

.if !defined(CMAKE39_BUILDLINK3_MK)
CMAKE39_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cmake39+=	cmake39>=2.8.5nb1<3.10
BUILDLINK_PKGSRCDIR.cmake39?=	../../devel/cmake39
BUILDLINK_DEPMETHOD.cmake39?=	build
BUILDLINK_FILES.cmake39+=	share/cmake-*/include/*
.endif # CMAKE39_BUILDLINK3_MK

BUILDLINK_TREE+=	-cmake39
