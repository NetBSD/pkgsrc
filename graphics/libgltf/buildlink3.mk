# $NetBSD: buildlink3.mk,v 1.1 2014/10/13 21:50:10 ryoon Exp $

BUILDLINK_TREE+=	libgltf

.if !defined(LIBGLTF_BUILDLINK3_MK)
LIBGLTF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgltf+=	libgltf>=0.0.2
BUILDLINK_PKGSRCDIR.libgltf?=	../../graphics/libgltf

.endif	# LIBGLTF_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgltf
