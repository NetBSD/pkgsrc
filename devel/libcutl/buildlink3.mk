# $NetBSD: buildlink3.mk,v 1.4 2024/10/04 03:49:20 ryoon Exp $

BUILDLINK_TREE+=	libcutl

.if !defined(LIBCUTL_BUILDLINK3_MK)
LIBCUTL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcutl+=	libcutl>=1.10.0
BUILDLINK_ABI_DEPENDS.libcutl?=	libcutl>=1.10.0nb7
BUILDLINK_PKGSRCDIR.libcutl?=	../../devel/libcutl

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.endif	# LIBCUTL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcutl
