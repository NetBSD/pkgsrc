# $NetBSD: buildlink3.mk,v 1.2 2022/04/14 13:20:42 nros Exp $

BUILDLINK_TREE+=	assimp

.if !defined(ASSIMP_BUILDLINK3_MK)
ASSIMP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.assimp+=	assimp>=5.0.1
BUILDLINK_ABI_DEPENDS.assimp+=	assimp>=5.2.3
BUILDLINK_PKGSRCDIR.assimp?=	../../multimedia/assimp

.include "../../devel/zlib/buildlink3.mk"
.endif	# ASSIMP_BUILDLINK3_MK

BUILDLINK_TREE+=	-assimp
