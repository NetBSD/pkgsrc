# $NetBSD: buildlink3.mk,v 1.1 2026/11/08 14:53:40 ryoon Exp $

BUILDLINK_TREE+=	manifold-geometry

.if !defined(MANIFOLD_GEOMETRY_BUILDLINK3_MK)
MANIFOLD_GEOMETRY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.manifold-geometry+=	manifold-geometry>=3.5.3
BUILDLINK_PKGSRCDIR.manifold-geometry?=		../../graphics/manifold-geometry

.include "../../cad/clipper2/buildlink3.mk"
.endif	# MANIFOLD_GEOMETRY_BUILDLINK3_MK

BUILDLINK_TREE+=	-manifold-geometry
