# $NetBSD: buildlink3.mk,v 1.3 2019/12/29 23:20:52 pho Exp $

BUILDLINK_TREE+=	hs-zlib

.if !defined(HS_ZLIB_BUILDLINK3_MK)
HS_ZLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-zlib+=	hs-zlib>=0.6.2
BUILDLINK_ABI_DEPENDS.hs-zlib+=	hs-zlib>=0.6.2.1
BUILDLINK_PKGSRCDIR.hs-zlib?=	../../archivers/hs-zlib

.include "../../devel/zlib/buildlink3.mk"
.endif	# HS_ZLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-zlib
