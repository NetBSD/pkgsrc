#	$NetBSD: buildlink3.mk,v 1.1 2025/01/23 23:27:25 riastradh Exp $

BUILDLINK_TREE+=	extra-cmake-modules

.if !defined(EXTRA_CMAKE_MODULES_BUILDLINK3_MK)
EXTRA_CMAKE_MODULES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.extra-cmake-modules+=	extra-cmake-modules>=6.8.0
BUILDLINK_PKGSRCDIR.extra-cmake-modules=	../../devel/extra-cmake-modules
BUILDLINK_DEPMETHOD.extra-cmake-modules?=	build
BUILDLINK_FILES.extra-cmake-modules+=		share/ECM/*/*
.endif				# EXTRA_CMAKE_MODULES_BUILDLINK3_MK

BUILDLINK_TREE+=	-extra-cmake-modules
