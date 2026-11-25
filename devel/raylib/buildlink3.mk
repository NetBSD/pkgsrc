# $NetBSD: buildlink3.mk,v 1.2 2026/11/25 14:42:03 wiz Exp $

BUILDLINK_TREE+=	raylib

.if !defined(RAYLIB_BUILDLINK3_MK)
RAYLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.raylib+=	raylib>=6.2
BUILDLINK_PKGSRCDIR.raylib?=	../../devel/raylib

#.include "../../mk/mesa.buildlink3.mk"
#.include "../../graphics/glfw/buildlink3.mk"
.endif	# RAYLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-raylib
