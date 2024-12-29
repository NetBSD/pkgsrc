# $NetBSD: buildlink3.mk,v 1.5 2024/12/29 15:09:44 adam Exp $

BUILDLINK_TREE+=	libcutl

.if !defined(LIBCUTL_BUILDLINK3_MK)
LIBCUTL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcutl+=	libcutl>=1.10.0
BUILDLINK_ABI_DEPENDS.libcutl+=	libcutl>=1.10.0nb8
BUILDLINK_PKGSRCDIR.libcutl?=	../../devel/libcutl

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.endif	# LIBCUTL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcutl
