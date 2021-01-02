# $NetBSD: buildlink3.mk,v 1.1 2021/01/02 07:35:44 pin Exp $

BUILDLINK_TREE+=	assimp

.if !defined(ASSIMP_BUILDLINK3_MK)
ASSIMP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.assimp+=	assimp>=5.0.1
BUILDLINK_PKGSRCDIR.assimp?=	../../multimedia/assimp

.include "../../devel/zlib/buildlink3.mk"
.endif	# ASSIMP_BUILDLINK3_MK

BUILDLINK_TREE+=	-assimp
