# $NetBSD: buildlink3.mk,v 1.9 2009/08/26 19:56:39 sno Exp $

BUILDLINK_TREE+=	libflash

.if !defined(LIBFLASH_BUILDLINK3_MK)
LIBFLASH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libflash+=	libflash>=0.4.10nb4
BUILDLINK_ABI_DEPENDS.libflash+=	libflash>=0.4.10nb7
BUILDLINK_PKGSRCDIR.libflash?=	../../multimedia/libflash

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.endif # LIBFLASH_BUILDLINK3_MK

BUILDLINK_TREE+=	-libflash
