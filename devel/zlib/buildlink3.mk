# $NetBSD: buildlink3.mk,v 1.25 2013/12/04 14:14:33 obache Exp $

BUILDLINK_TREE+=	zlib

.if !defined(ZLIB_BUILDLINK3_MK)
ZLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.zlib+=	zlib>=1.1.4
BUILDLINK_ABI_DEPENDS.zlib+=	zlib>=1.2.3
BUILDLINK_PKGSRCDIR.zlib?=	../../devel/zlib
.endif # ZLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-zlib
