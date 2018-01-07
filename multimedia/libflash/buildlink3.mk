# $NetBSD: buildlink3.mk,v 1.13 2018/01/07 13:04:24 rillig Exp $

BUILDLINK_TREE+=	libflash

.if !defined(LIBFLASH_BUILDLINK3_MK)
LIBFLASH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libflash+=	libflash>=0.4.10nb4
BUILDLINK_ABI_DEPENDS.libflash+=	libflash>=0.4.10nb9
BUILDLINK_PKGSRCDIR.libflash?=		../../multimedia/libflash

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.endif # LIBFLASH_BUILDLINK3_MK

BUILDLINK_TREE+=	-libflash
