# $NetBSD: buildlink3.mk,v 1.14 2024/05/09 01:31:39 pho Exp $

BUILDLINK_TREE+=	hs-zlib

.if !defined(HS_ZLIB_BUILDLINK3_MK)
HS_ZLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-zlib+=	hs-zlib>=0.7.1
BUILDLINK_ABI_DEPENDS.hs-zlib+=	hs-zlib>=0.7.1.0nb1
BUILDLINK_PKGSRCDIR.hs-zlib?=	../../archivers/hs-zlib

.include "../../devel/zlib/buildlink3.mk"
.endif	# HS_ZLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-zlib
