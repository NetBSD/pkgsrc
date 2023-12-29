# $NetBSD: buildlink3.mk,v 1.3 2023/12/29 18:24:41 adam Exp $

BUILDLINK_TREE+=	libcutl

.if !defined(LIBCUTL_BUILDLINK3_MK)
LIBCUTL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcutl+=	libcutl>=1.10.0
BUILDLINK_ABI_DEPENDS.libcutl?=	libcutl>=1.10.0nb6
BUILDLINK_PKGSRCDIR.libcutl?=	../../devel/libcutl

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.endif	# LIBCUTL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcutl
