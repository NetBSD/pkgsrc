# $NetBSD: buildlink3.mk,v 1.24 2009/03/20 19:24:31 joerg Exp $

BUILDLINK_TREE+=	zlib

.if !defined(ZLIB_BUILDLINK3_MK)
ZLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.zlib+=	zlib>=1.1.4nb1
BUILDLINK_ABI_DEPENDS.zlib+=	zlib>=1.2.3
BUILDLINK_PKGSRCDIR.zlib?=	../../devel/zlib
.endif # ZLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-zlib
