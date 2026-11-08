# $NetBSD: buildlink3.mk,v 1.1 2026/11/08 16:39:33 ryoon Exp $

BUILDLINK_TREE+=	raylib

.if !defined(RAYLIB_BUILDLINK3_MK)
RAYLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.raylib+=	raylib>=6.2
BUILDLINK_PKGSRCDIR.raylib?=	../../devel/raylib

#.include "../../graphics/MesaLib/buildlink3.mk"
#.include "../../graphics/glfw/buildlink3.mk"
.endif	# RAYLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-raylib
