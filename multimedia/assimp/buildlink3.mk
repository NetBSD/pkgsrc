# $NetBSD: buildlink3.mk,v 1.3 2025/06/08 07:46:04 wiz Exp $

BUILDLINK_TREE+=	assimp

.if !defined(ASSIMP_BUILDLINK3_MK)
ASSIMP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.assimp+=	assimp>=5.0.1
BUILDLINK_ABI_DEPENDS.assimp+=	assimp>=6.0.1
BUILDLINK_PKGSRCDIR.assimp?=	../../multimedia/assimp

.include "../../devel/zlib/buildlink3.mk"
.endif	# ASSIMP_BUILDLINK3_MK

BUILDLINK_TREE+=	-assimp
